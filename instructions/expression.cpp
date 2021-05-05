#include "expression.hpp"

namespace antiwasm {
std::vector<Instruction> Expression::getInstructionVector() { return instructionVector; }

void Expression::addInstruction(Instruction instr) { instructionVector.push_back(instr); }

Expression parseExpression(uint8_t *expressionContent);
} // namespace antiwasm