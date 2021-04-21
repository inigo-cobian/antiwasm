#include "nameParser.hpp"

namespace antiwasm {

string parseUTF8Name(const uint8_t *bytes, uint32_t size) {
  return string(reinterpret_cast<const char *>(bytes), size);
}

} // namespace antiwasm
