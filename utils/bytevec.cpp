#include "bytevec.hpp"

#include <memory>

namespace antiwasm {
ByteVec::ByteVec(uint8_t *byteVecContent) {
  size = transformLeb128ToUnsignedInt32(byteVecContent);
  auto pos = sizeOfLeb128(byteVecContent);

  bytes = new uint8_t[pos];
  bytes = byteVecContent + pos;
}

} // namespace antiwasm
