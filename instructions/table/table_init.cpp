#include "table_init.hpp"

namespace antiwasm {
TableInit::TableInit(const uint8_t *instructionContent) {
  instructionCode = double_byte_instr;
  secondCode = Table_init;
  elemidx = transformLeb128ToUnsignedInt32(instructionContent + 2);
  nBytes = 2 + sizeOfLeb128(instructionContent + 2);
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + nBytes);
  nBytes += sizeOfLeb128(instructionContent + nBytes);
}
} // namespace antiwasm