#include "memory_init.hpp"

namespace antiwasm {
MemoryInit::MemoryInit(const uint8_t *instrContent) {
  instructionCode = double_byte_instr;
  secondCode = Memory_init;
  dataidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm
