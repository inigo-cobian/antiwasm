#ifndef ANTIWASM_MEMORY_GROW_HPP
#define ANTIWASM_MEMORY_GROW_HPP

#include "instruction.hpp"

namespace antiwasm {
class MemoryGrow : public Instruction {

public:
  explicit MemoryGrow();
  virtual ~MemoryGrow() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_MEMORY_GROW_HPP
