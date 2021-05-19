#ifndef ANTIWASM_RETURN_HPP
#define ANTIWASM_RETURN_HPP

#include "instruction.hpp"

namespace antiwasm {
class ReturnInstr : public Instruction {
public:
  explicit ReturnInstr();
  virtual ~ReturnInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_RETURN_HPP
