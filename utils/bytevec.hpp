#ifndef ANTIWASM_BYTEVEC_HPP
#define ANTIWASM_BYTEVEC_HPP

#include "contentBlock.hpp"
#include "leb128.hpp"
#include <iomanip>
#include <sstream>

namespace antiwasm {
struct ByteVec : public ContentBlock {
  uint32_t size{};
  uint8_t *bytes;

  explicit ByteVec(const uint8_t *byteVecContent);
  ByteVec() = default;
  std::string getAsText() const;
};

} // namespace antiwasm

#endif // ANTIWASM_BYTEVEC_HPP
