#include "local_tee.hpp"

namespace antiwasm {
LocalTee::LocalTee(const uint8_t *localidx_) {
  instructionCode = Local_tee;
  localidx = transformLeb128ToUnsignedInt32(localidx_);
  nBytes = 1 + sizeOfLeb128(localidx_);
}
} // namespace antiwasm