#ifndef ANTIWASM_F64_COMPARISON_HPP
#define ANTIWASM_F64_COMPARISON_HPP

#include "instruction.hpp"

namespace antiwasm {
class F64Comp : public Instruction {

public:
  explicit F64Comp(const uint8_t *content);
  virtual ~F64Comp() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F64_COMPARISON_HPP
