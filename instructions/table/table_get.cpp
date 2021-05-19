#include "table_get.hpp"

namespace antiwasm {
TableGet::TableGet(const uint8_t *instructionContent) {
  instructionCode = Table_get;
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + 1);
  nBytes = 1 + sizeOfLeb128(instructionContent + 1);
}
} // namespace antiwasm