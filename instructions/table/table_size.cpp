#include "table_size.hpp"

namespace antiwasm {
TableSize::TableSize(const uint8_t *instructionContent) {
  instructionCode = double_byte_instr;
  secondCode = Table_size;
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + 2);
  nBytes = 2 + sizeOfLeb128(instructionContent + 2);
}
} // namespace antiwasm