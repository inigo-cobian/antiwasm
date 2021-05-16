#include "i64_load.hpp"

namespace antiwasm {
I64Load::I64Load(const uint8_t *memarg_) : memArg(memarg_){
  instructionCode = i64_load;
  nBytes = memArg.getNBytes() + 1;
}
} // namespace antiwasm