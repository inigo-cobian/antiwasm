#ifndef ANTIWASM_END_HPP
#define ANTIWASM_END_HPP

#include "instruction.hpp"

namespace antiwasm {
class EndInstr : public Instruction {
public:
  explicit EndInstr();
  virtual ~EndInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_END_HPP
