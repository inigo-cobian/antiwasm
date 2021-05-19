#include "table_set.hpp"

namespace antiwasm {
TableSet::TableSet(const uint8_t *instructionContent) {
  instructionCode = Table_set;
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + 1);
  nBytes = 1 + sizeOfLeb128(instructionContent + 1);
}
} // namespace antiwasm