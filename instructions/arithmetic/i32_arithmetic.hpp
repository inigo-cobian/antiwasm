#ifndef ANTIWASM_I32_ARITHMETIC_HPP
#define ANTIWASM_I32_ARITHMETIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class I32Arithmetic : public Instruction {

public:
  explicit I32Arithmetic(const uint8_t *content);
  virtual ~I32Arithmetic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32_ARITHMETIC_HPP
