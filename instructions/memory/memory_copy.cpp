#include "memory_copy.hpp"

namespace antiwasm {
MemoryCopy::MemoryCopy() {
  instructionCode = double_byte_instr;
  secondCode = Memory_copy;
  nBytes = 2;
}
} // namespace antiwasm
