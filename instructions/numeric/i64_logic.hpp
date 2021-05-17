#ifndef ANTIWASM_I64_LOGIC_HPP
#define ANTIWASM_I64_LOGIC_HPP

#include "instruction.hpp"

namespace antiwasm {
class I64Logic : public Instruction {

public:
  explicit I64Logic(const uint8_t *content);
  virtual ~I64Logic() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I64_LOGIC_HPP
