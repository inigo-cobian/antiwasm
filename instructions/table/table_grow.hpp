#ifndef ANTIWASM_TABLE_GROW_HPP
#define ANTIWASM_TABLE_GROW_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class TableGrow : public Instruction {
  uint32_t tableidx;

public:
  explicit TableGrow(const uint8_t *instructionContent);
  virtual ~TableGrow() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_GROW_HPP
