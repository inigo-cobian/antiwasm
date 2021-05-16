#include "f32_load.hpp"

namespace antiwasm {
F32Load::F32Load(const uint8_t *memarg_) : memArg(memarg_) {
  instructionCode = f32_load;
  nBytes = memArg.getNBytes() + 1;
}
} // namespace antiwasm