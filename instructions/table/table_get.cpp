#include "table_get.hpp"

namespace antiwasm {
TableGet::TableGet(const uint8_t *instrContent) {
  instructionCode = Table_get;
  tableidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm