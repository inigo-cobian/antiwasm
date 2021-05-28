#ifndef ANTIWASM_SELECT_HPP
#define ANTIWASM_SELECT_HPP

#include "instruction.hpp"

namespace antiwasm {
class SelectInstr : public Instruction {

public:
  explicit SelectInstr();
  virtual ~SelectInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_SELECT_HPP
