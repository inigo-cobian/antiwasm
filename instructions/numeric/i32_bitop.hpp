#ifndef ANTIWASM_I32_BITOP_HPP
#define ANTIWASM_I32_BITOP_HPP

#include "instruction.hpp"

namespace antiwasm {
class I32BitOp : public Instruction {

public:
  explicit I32BitOp(const uint8_t *content);
  virtual ~I32BitOp() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32_BITOP_HPP
