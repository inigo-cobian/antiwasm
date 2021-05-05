#include "expression.hpp"

std::vector<Instruction> antiwasm::Expression::getInstructionVector() { return instructionVector; }

void antiwasm::Expression::addInstruction(Instruction instr) {
  instructionVector.push_back(instr);
}
