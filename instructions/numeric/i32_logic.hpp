#ifndef ANTIWASM_I32_LOGIC_HPP
#define ANTIWASM_I32_LOGIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class I32Logic : public Instruction {

public:
  explicit I32Logic(const uint8_t *content);
  virtual ~I32Logic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32_LOGIC_HPP
