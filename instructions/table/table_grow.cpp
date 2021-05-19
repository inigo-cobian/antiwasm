#include "table_grow.hpp"

namespace antiwasm {
TableGrow::TableGrow(const uint8_t *instructionContent) {
  instructionCode = double_byte_instr;
  secondCode = Table_grow;
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + 2);
  nBytes = 2 + sizeOfLeb128(instructionContent + 2);
}
} // namespace antiwasm