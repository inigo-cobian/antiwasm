#include "i32_load_8u.hpp"

namespace antiwasm {
I32Load8u::I32Load8u(const uint8_t *memarg_) : memArg(memarg_){
  instructionCode = i32_load8_u;
  nBytes = memArg.getNBytes() + 1;
}
} // namespace antiwasm