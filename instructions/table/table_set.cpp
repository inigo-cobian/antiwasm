#include "table_set.hpp"

namespace antiwasm {
TableSet::TableSet(const uint8_t *instrContent) {
  instructionCode = Table_set;
  tableidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm