#include "expression.hpp"

namespace antiwasm {
std::vector<Instruction> Expression::getInstructionVector() { return instructionVector; }

void Expression::addInstruction(const Instruction &instr) {
  instructionVector.push_back(instr);
  addNBytes(instr.getNBytes());
}

Expression parseExpression(const uint8_t *expressionContent) {
  Expression expr{};
  size_t pointer = 0;
  int nInstr = 0;

  while (expressionContent[pointer] != InstructionSet::End) {
    BOOST_LOG_TRIVIAL(debug) << "[expression] Next instruction has code: " << std::hex
                             << (int)expressionContent[pointer];

    auto instr = parseInstruction(&expressionContent[pointer]);
    expr.addInstruction(*instr);
    if (instr->hasError()) {
      BOOST_LOG_TRIVIAL(error) << "[expression] Error: invalid Instruction At Expression with value " << std::hex
                               << (int)expressionContent[pointer];
      auto error = generateError(fatal, invalidInstructionAtExpression, nInstr);
      expr.addError(error);
      break;
    }
    nInstr++;
    BOOST_LOG_TRIVIAL(debug) << "[expression] Size of instruction: " << instr->getNBytes();
    pointer += instr->getNBytes();
  }

  expr.addInstruction(EndInstr());

  BOOST_LOG_TRIVIAL(debug) << "[expression] There are " << nInstr << " instructions at the expression";
  BOOST_LOG_TRIVIAL(debug) << "[expression] Final nBytes of expression is " << expr.getNBytes();

  return expr;
}

} // namespace antiwasm