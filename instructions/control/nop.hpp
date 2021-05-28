#ifndef ANTIWASM_NOP_HPP
#define ANTIWASM_NOP_HPP

#include "instruction.hpp"

namespace antiwasm {
class NopInstr : public Instruction {
public:
  explicit NopInstr();
  virtual ~NopInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_NOP_HPP
