#include "memory_init.hpp"

namespace antiwasm {
MemoryInit::MemoryInit(const uint8_t * dataidx_) {
  instructionCode = double_byte_instr;
  secondCode = Memory_init;
  dataidx = transformLeb128ToUnsignedInt32(dataidx_);
  nBytes = 1 + sizeOfLeb128(dataidx_);
}
} // namespace antiwasm
