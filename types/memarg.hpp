#ifndef ANTIWASM_MEMARG_HPP
#define ANTIWASM_MEMARG_HPP

#include "contentBlock.hpp"
#include "leb128.hpp"
#include <cstdint>

namespace antiwasm {
struct MemArg : public ContentBlock {
  uint32_t offset;
  uint32_t align;

  MemArg(uint32_t offset_, uint32_t align_);
  ~MemArg() = default;
};

MemArg parseMemArg(const uint8_t *memTypeContent);

} // namespace antiwasm

#endif // ANTIWASM_MEMARG_HPP
