#ifndef ANTIWASM_F32_LOAD_HPP
#define ANTIWASM_F32_LOAD_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class F32Load : public Instruction {
  MemArg memArg;

public:
  explicit F32Load(const uint8_t *memarg_);
  virtual ~F32Load() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F32_LOAD_HPP
