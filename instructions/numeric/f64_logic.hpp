#ifndef ANTIWASM_F64_LOGIC_HPP
#define ANTIWASM_F64_LOGIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class F64Logic : public Instruction {

public:
  explicit F64Logic(const uint8_t *content);
  virtual ~F64Logic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F64_LOGIC_HPP
