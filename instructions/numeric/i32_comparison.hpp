#ifndef ANTIWASM_I32_COMPARISON_HPP
#define ANTIWASM_I32_COMPARISON_HPP

#include "instruction.hpp"

namespace antiwasm {
class I32Comp : public Instruction {

public:
  explicit I32Comp(const uint8_t *content);
  virtual ~I32Comp() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32_COMPARISON_HPP
