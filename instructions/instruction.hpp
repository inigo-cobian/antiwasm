#ifndef ANTIWASM_INSTRUCTION_HPP
#define ANTIWASM_INSTRUCTION_HPP

#include "lexems.hpp"
#include <cstdint>

namespace antiwasm {
class Instruction : public ContentBlock {
protected:
  InstructionSet instructionCode;

public:
  Instruction() { instructionCode = End; };
  ~Instruction() {;};
  InstructionSet getInstructionCode();
};

} // namespace antiwasm
#endif // ANTIWASM_INSTRUCTION_HPP
