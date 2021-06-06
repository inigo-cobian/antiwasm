#include "bytevec.hpp"

namespace antiwasm {
ByteVec::ByteVec(const uint8_t *byteVecContent) {
  size = transformLeb128ToUnsignedInt32(byteVecContent);
  auto pos = sizeOfLeb128(byteVecContent);

  bytes = new uint8_t[pos];
  bytes = const_cast<uint8_t *>(byteVecContent) + pos;
}

std::string ByteVec::getAsText() const {
  std::stringstream byteVecAsText;

  for(int i = 0; i < size; i++) {
    byteVecAsText << std::hex << std::setw(2) << static_cast<unsigned int>(bytes[i]);
  }
  return byteVecAsText.str();
}

} // namespace antiwasm
