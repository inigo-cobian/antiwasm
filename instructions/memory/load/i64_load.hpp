#ifndef ANTIWASM_I64_LOAD_HPP
#define ANTIWASM_I64_LOAD_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class I64Load : public Instruction {
  MemArg memArg;

public:
  explicit I64Load(const uint8_t *memarg_);
  virtual ~I64Load() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I64_LOAD_HPP
