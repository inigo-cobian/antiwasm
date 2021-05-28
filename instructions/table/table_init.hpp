#ifndef ANTIWASM_TABLE_INIT_HPP
#define ANTIWASM_TABLE_INIT_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class TableInit : public Instruction {
  uint32_t elemidx;
  uint32_t tableidx;

public:
  explicit TableInit(const uint8_t *instructionContent);
  virtual ~TableInit() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_INIT_HPP
