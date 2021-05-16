#include "instruction.hpp"

namespace antiwasm {

SecondByteSet DoubleByteInstruction::getSecondByte() { return secondCode; }

InstructionSet Instruction::getInstructionCode() { return instructionCode; }

} // namespace antiwasm