#ifndef ANTIWASM_TABLE_SET_HPP
#define ANTIWASM_TABLE_SET_HPP

#include "instruction.hpp"
#include "leb128.hpp"
#include <cstdint>

namespace antiwasm {
class TableSet : public Instruction {
  uint32_t tableidx;

public:
  explicit TableSet(const uint8_t *instrContent);
  virtual ~TableSet() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_SET_HPP
