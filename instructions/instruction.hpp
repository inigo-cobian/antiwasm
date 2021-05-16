#ifndef ANTIWASM_INSTRUCTION_HPP
#define ANTIWASM_INSTRUCTION_HPP

#include "contentBlock.hpp"
#include "lexems.hpp"
#include <cstdint>

namespace antiwasm {
class DoubleByteInstruction {
protected:
  SecondByteSet secondCode;

public:
  virtual SecondByteSet getSecondByte();
};

class Instruction : public ContentBlock {
protected:
  InstructionSet instructionCode;

public:
  Instruction() { instructionCode = End; };
  ~Instruction() = default;
  InstructionSet getInstructionCode();
};

} // namespace antiwasm
#endif // ANTIWASM_INSTRUCTION_HPP
