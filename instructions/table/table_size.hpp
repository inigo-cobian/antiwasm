#ifndef ANTIWASM_TABLE_SIZE_HPP
#define ANTIWASM_TABLE_SIZE_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class TableSize : public Instruction {
  uint32_t tableidx;

public:
  explicit TableSize(const uint8_t *instructionContent);
  virtual ~TableSize() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_SIZE_HPP
