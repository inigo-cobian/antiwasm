#ifndef ANTIWASM_CALL_HPP
#define ANTIWASM_CALL_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class CallInstr : public Instruction {
  uint32_t funcidx;

public:
  explicit CallInstr(const uint8_t *instrContent);
  virtual ~CallInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_CALL_HPP
