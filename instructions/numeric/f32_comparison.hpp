#ifndef ANTIWASM_F32_COMPARISON_HPP
#define ANTIWASM_F32_COMPARISON_HPP

#include "instruction.hpp"

namespace antiwasm {
class F32Comp : public Instruction {

public:
  explicit F32Comp(const uint8_t *content);
  virtual ~F32Comp() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F32_COMPARISON_HPP
