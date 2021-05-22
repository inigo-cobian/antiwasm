#ifndef ANTIWASM_MEMORY_INIT_HPP
#define ANTIWASM_MEMORY_INIT_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class MemoryInit : public Instruction {
  uint32_t dataidx;

public:
  explicit MemoryInit(const uint8_t *instrContent);
  virtual ~MemoryInit() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_MEMORY_INIT_HPP
