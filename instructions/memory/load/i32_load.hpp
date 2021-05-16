#ifndef ANTIWASM_I32_LOAD_HPP
#define ANTIWASM_I32_LOAD_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class I32Load : public Instruction {
  MemArg memArg;

public:
  explicit I32Load(const uint8_t *memarg_);
  virtual ~I32Load() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32_LOAD_HPP
