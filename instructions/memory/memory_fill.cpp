#include "memory_fill.hpp"

namespace antiwasm {
MemoryFill::MemoryFill() {
  instructionCode = double_byte_instr;
  secondCode = memory_fill;
  nBytes = 2;
}
} // namespace antiwasm
