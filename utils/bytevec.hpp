#ifndef ANTIWASM_BYTEVEC_HPP
#define ANTIWASM_BYTEVEC_HPP

#include "leb128.hpp"
#include <sstream>
#include <iomanip>

namespace antiwasm {
struct ByteVec {
  uint32_t size{};
  uint8_t *bytes{};

  explicit ByteVec(const uint8_t *byteVecContent);
  ByteVec() = default;
  [[nodiscard]] std::string getAsText() const;
};

} // namespace antiwasm

#endif // ANTIWASM_BYTEVEC_HPP
