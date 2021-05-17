#ifndef ANTIWASM_I64_COMPARISON_HPP
#define ANTIWASM_I64_COMPARISON_HPP

#include "instruction.hpp"

namespace antiwasm {
class I64Comp : public Instruction {

public:
  explicit I64Comp(const uint8_t *content);
  virtual ~I64Comp() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I64_COMPARISON_HPP
