#ifndef ANTIWASM_TABLE_COPY_HPP
#define ANTIWASM_TABLE_COPY_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class TableCopy : public Instruction {
  uint32_t elemidx;
  uint32_t tableidx;

public:
  explicit TableCopy(const uint8_t *instructionContent);
  virtual ~TableCopy() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_COPY_HPP
