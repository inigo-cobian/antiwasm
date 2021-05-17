#ifndef ANTIWASM_I64_BITOP_HPP
#define ANTIWASM_I64_BITOP_HPP

#include "instruction.hpp"

namespace antiwasm {
class I64BitOp : public Instruction {

public:
  explicit I64BitOp(const uint8_t *content);
  virtual ~I64BitOp() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I64_BITOP_HPP
