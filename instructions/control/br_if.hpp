#ifndef ANTIWASM_BR_IF_HPP
#define ANTIWASM_BR_IF_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class BrIfInstr : public Instruction {
  uint32_t labelidx;

public:
  explicit BrIfInstr(const uint8_t *instrContent);
  virtual ~BrIfInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_BR_IF_HPP
