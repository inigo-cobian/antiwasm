#include "f64_load.hpp"

namespace antiwasm {
F64Load::F64Load(const uint8_t *memarg_) : memArg(memarg_){
  instructionCode = f64_load;
  nBytes = memArg.getNBytes() + 1;
}
} // namespace antiwasm