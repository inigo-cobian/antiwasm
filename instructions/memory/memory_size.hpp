#ifndef ANTIWASM_MEMORY_SIZE_HPP
#define ANTIWASM_MEMORY_SIZE_HPP

#include "instruction.hpp"

namespace antiwasm {
class MemorySize : public Instruction {

public:
  explicit MemorySize();
  virtual ~MemorySize() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_MEMORY_SIZE_HPP
