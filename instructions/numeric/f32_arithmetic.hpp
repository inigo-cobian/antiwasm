#ifndef ANTIWASM_F32_ARITHMETIC_HPP
#define ANTIWASM_F32_ARITHMETIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class F32Arithmetic : public Instruction {

public:
  explicit F32Arithmetic(const uint8_t *content);
  virtual ~F32Arithmetic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F32_ARITHMETIC_HPP
