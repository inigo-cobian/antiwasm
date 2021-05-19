#include "table_copy.hpp"

namespace antiwasm {
TableCopy::TableCopy(const uint8_t *instructionContent) {
  instructionCode = double_byte_instr;
  secondCode = Table_copy;
  elemidx = transformLeb128ToUnsignedInt32(instructionContent + 2);
  nBytes = 2 + sizeOfLeb128(instructionContent + 2);
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + nBytes);
  nBytes += sizeOfLeb128(instructionContent + nBytes);
}
} // namespace antiwasm