#ifndef ANTIWASM_I64CONST_HPP
#define ANTIWASM_I64CONST_HPP

#include <cstdint>
#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class I64Const : public Instruction {
  int64_t constant;

public:
  explicit I64Const(const uint8_t *i64Const);
  virtual ~I64Const() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I64CONST_HPP
