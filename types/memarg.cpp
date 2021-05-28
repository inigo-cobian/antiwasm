#include "memarg.hpp"

namespace antiwasm {
MemArg::MemArg(uint32_t offset_, uint32_t align_) : offset(offset_), align(align_) {}

MemArg parseMemArg(const uint8_t *memTypeContent) {
  auto offset = transformLeb128ToUnsignedInt32(memTypeContent);
  auto nBytes = sizeOfLeb128(memTypeContent);
  auto align = transformLeb128ToUnsignedInt32(memTypeContent + nBytes);

  MemArg memArg{offset, align};

  nBytes += sizeOfLeb128(memTypeContent + nBytes);
  memArg.setNBytes(nBytes);

  return memArg;
}
} // namespace antiwasm