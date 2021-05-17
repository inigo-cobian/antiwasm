#ifndef ANTIWASM_I64_ARITHMETIC_HPP
#define ANTIWASM_I64_ARITHMETIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class I64Arithmetic : public Instruction {

public:
  explicit I64Arithmetic(const uint8_t *content);
  virtual ~I64Arithmetic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I64_ARITHMETIC_HPP
