#include "i32_load_8s.hpp"

namespace antiwasm {
I32Load8s::I32Load8s(const uint8_t *memarg_) : memArg(memarg_) {
  instructionCode = i32_load8_s;
  nBytes = memArg.getNBytes() + 1;
}
} // namespace antiwasm