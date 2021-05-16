#include "local_set.hpp"

namespace antiwasm {
LocalSet::LocalSet(const uint8_t *localidx_) {
  instructionCode = Local_set;
  localidx = transformLeb128ToUnsignedInt32(localidx_);
  nBytes = 1 + sizeOfLeb128(localidx_);
}
} // namespace antiwasm