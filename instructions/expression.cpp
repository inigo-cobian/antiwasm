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
    BOOST_LOG_TRIVIAL(debug) << "[expression] Next intruction has code: " << std::hex
                             << (int)expressionContent[pointer];

    auto instr = parseInstruction(&expressionContent[pointer]);
    expr.addInstruction(*instr);
    if (instr->hasError()) {
      auto error = generateError(fatal, invalidInstructionAtExpression, nInstr);
      expr.addError(error);
      break;
    }
    nInstr++;
    pointer += expr.getNBytes();
  }
  BOOST_LOG_TRIVIAL(debug) << "[expression] There are " << nInstr << " instructions at the expression";

  return expr;
}

} // namespace antiwasm