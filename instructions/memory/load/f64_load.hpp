#ifndef ANTIWASM_F64_LOAD_HPP
#define ANTIWASM_F64_LOAD_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class F64Load : public Instruction {
  MemArg memArg;

public:
  explicit F64Load(const uint8_t *memarg_);
  virtual ~F64Load() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F64_LOAD_HPP
