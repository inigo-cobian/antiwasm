#include "memory_size.hpp"

namespace antiwasm {
MemorySize::MemorySize() {
  instructionCode = Memory_size;
  nBytes = 1;
}
} // namespace antiwasm
