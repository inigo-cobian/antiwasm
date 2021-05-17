#ifndef ANTIWASM_F32_LOGIC_HPP
#define ANTIWASM_F32_LOGIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class F32Logic : public Instruction {

public:
  explicit F32Logic(const uint8_t *content);
  virtual ~F32Logic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F32_LOGIC_HPP
