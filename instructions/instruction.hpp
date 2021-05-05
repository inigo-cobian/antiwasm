#ifndef ANTIWASM_INSTRUCTION_HPP
#define ANTIWASM_INSTRUCTION_HPP

#include "lexems.hpp"
#include <cstdint>

class Instruction {
protected:
  InstructionSet instructionCode_;

public:
  virtual ~Instruction() {}

  virtual InstructionSet getInstructionCode() { return instructionCode_; };
};

#endif // ANTIWASM_INSTRUCTION_HPP
