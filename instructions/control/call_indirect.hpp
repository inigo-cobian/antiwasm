#ifndef ANTIWASM_CALL_INDIRECT_HPP
#define ANTIWASM_CALL_INDIRECT_HPP

#include "instruction.hpp"
#include "leb128.hpp"
#include <cstdint>

namespace antiwasm {
class CallIndirectInstr : public Instruction {
  uint32_t typeidx;
  uint32_t tableidx;

public:
  explicit CallIndirectInstr(const uint8_t *instrContent);
  virtual ~CallIndirectInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_CALL_INDIRECT_HPP
