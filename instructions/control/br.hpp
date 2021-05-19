#ifndef ANTIWASM_BR_HPP
#define ANTIWASM_BR_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class BrInstr : public Instruction {
  uint32_t labelidx;

public:
  explicit BrInstr(const uint8_t *instrContent);
  virtual ~BrInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_BR_HPP
