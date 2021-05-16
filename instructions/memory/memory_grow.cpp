#include "memory_grow.hpp"

namespace antiwasm {
MemoryGrow::MemoryGrow() {
  instructionCode = Memory_grow;
  nBytes = 1;
}
} // namespace antiwasm
