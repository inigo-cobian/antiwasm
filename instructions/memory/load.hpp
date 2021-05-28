#ifndef ANTIWASM_LOAD_HPP
#define ANTIWASM_LOAD_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class LoadInstr : public Instruction {
  MemArg memArg;

public:
  explicit LoadInstr(const uint8_t *loadInstrContent);
  virtual ~LoadInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_LOAD_HPP
