#ifndef ANTIWASM_MEMORY_FILL_HPP
#define ANTIWASM_MEMORY_FILL_HPP

#include "instruction.hpp"

namespace antiwasm {
class MemoryFill : public Instruction {

public:
  explicit MemoryFill();
  virtual ~MemoryFill() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_MEMORY_FILL_HPP
