#include "instruction.hpp"

namespace antiwasm {

InstructionSet Instruction::getInstructionCode() { return instructionCode; }

SecondByteSet Instruction::getSecondByte() { return secondCode; }

} // namespace antiwasm