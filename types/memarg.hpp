#ifndef ANTIWASM_MEMARG_HPP
#define ANTIWASM_MEMARG_HPP

#include "contentBlock.hpp"
#include "leb128.hpp"
#include <cstdint>

namespace antiwasm {
struct MemArg : public ContentBlock {
  uint32_t offset;
  uint32_t align;

  explicit MemArg(uint8_t *content);
  ~MemArg() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_MEMARG_HPP
