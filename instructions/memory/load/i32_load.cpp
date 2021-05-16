#include "i32_load.hpp"

namespace antiwasm {
I32Load::I32Load(const uint8_t *memarg_) : memArg(memarg_){
  nBytes = memArg.getNBytes() + 1;
}
} // namespace antiwasm