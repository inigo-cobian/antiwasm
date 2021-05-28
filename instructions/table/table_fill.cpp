#include "table_fill.hpp"

namespace antiwasm {
TableFill::TableFill(const uint8_t *instructionContent) {
  instructionCode = double_byte_instr;
  secondCode = Table_fill;
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + 2);
  nBytes = 2 + sizeOfLeb128(instructionContent + 2);
}
} // namespace antiwasm