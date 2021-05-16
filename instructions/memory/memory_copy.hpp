#ifndef ANTIWASM_MEMORY_COPY_HPP
#define ANTIWASM_MEMORY_COPY_HPP

#include "instruction.hpp"

namespace antiwasm {
class MemoryCopy : public Instruction, DoubleByteInstruction {

public:
  explicit MemoryCopy();
  virtual ~MemoryCopy() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_MEMORY_COPY_HPP
