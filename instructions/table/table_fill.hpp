#ifndef ANTIWASM_TABLE_FILL_HPP
#define ANTIWASM_TABLE_FILL_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class TableFill : public Instruction {
  uint32_t tableidx;

public:
  explicit TableFill(const uint8_t *instructionContent);
  virtual ~TableFill() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_FILL_HPP
