#include "expression.hpp"

namespace antiwasm {
std::vector<Instruction> Expression::getInstructionVector() { return instructionVector; }

void Expression::addInstruction(const Instruction &instr) { instructionVector.push_back(instr); }

Expression parseExpression(const uint8_t *expressionContent) {
  Expression expr{};
  size_t pointer = 0;
  while (expressionContent[pointer] != InstructionSet::End) {
    auto instr = parseInstruction(&expressionContent[pointer]);
  }
  return expr;
}

} // namespace antiwasm