#ifndef ANTIWASM_F64_ARITHMETIC_HPP
#define ANTIWASM_F64_ARITHMETIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class F64Arithmetic : public Instruction {

public:
  explicit F64Arithmetic(const uint8_t *content);
  virtual ~F64Arithmetic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F64_ARITHMETIC_HPP
