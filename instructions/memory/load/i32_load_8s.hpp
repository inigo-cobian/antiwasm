#ifndef ANTIWASM_I32_LOAD_8S_HPP
#define ANTIWASM_I32_LOAD_8S_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class I32Load8s : public Instruction {
  MemArg memArg;

public:
  explicit I32Load8s(const uint8_t *memarg_);
  virtual ~I32Load8s() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32_LOAD_8S_HPP
