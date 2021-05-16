#include "memarg.hpp"

namespace antiwasm {
MemArg::MemArg(const uint8_t *content) {
  offset = transformLeb128ToUnsignedInt32(content);
  nBytes = sizeOfLeb128(content);
  align = transformLeb128ToUnsignedInt32(content + nBytes);
  nBytes += sizeOfLeb128(content + nBytes);
}
} // namespace antiwasm