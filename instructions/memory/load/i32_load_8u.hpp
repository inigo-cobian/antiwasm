#ifndef ANTIWASM_I32_LOAD_8U_HPP
#define ANTIWASM_I32_LOAD_8U_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class I32Load8u : public Instruction {
  MemArg memArg;

public:
  explicit I32Load8u(const uint8_t *memarg_);
  virtual ~I32Load8u() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32_LOAD_8U_HPP
