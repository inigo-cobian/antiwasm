#ifndef ANTIWASM_DROP_HPP
#define ANTIWASM_DROP_HPP

#include "instruction.hpp"

namespace antiwasm {
class DropInstr : public Instruction {

public:
  explicit DropInstr();
  virtual ~DropInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_DROP_HPP
