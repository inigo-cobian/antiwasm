#ifndef ANTIWASM_INSTRUCTION_HPP
#define ANTIWASM_INSTRUCTION_HPP

#include "contentBlock.hpp"
#include "lexems.hpp"
#include <cstdint>

namespace antiwasm {
class Instruction : public ContentBlock {
protected:
  InstructionSet instructionCode;
  SecondByteSet secondCode;

public:
  Instruction() {};
  ~Instruction() = default;
  InstructionSet getInstructionCode();
  SecondByteSet getSecondByte();
};

} // namespace antiwasm
#endif // ANTIWASM_INSTRUCTION_HPP
