#ifndef ANTIWASM_BYTEVEC_HPP
#define ANTIWASM_BYTEVEC_HPP

#include "leb128.hpp"

namespace antiwasm {
struct ByteVec {
  uint32_t size;
  uint8_t *bytes;

  explicit ByteVec(uint8_t *byteVecContent);
};

} // namespace antiwasm

#endif // ANTIWASM_BYTEVEC_HPP
