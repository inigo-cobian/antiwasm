#include "local_get.hpp"

namespace antiwasm {
antiwasm::LocalGet::LocalGet(const uint8_t *localidx_) {
  instructionCode = Local_get;
  localidx = transformLeb128ToUnsignedInt32(localidx_);
  nBytes = 1 + sizeOfLeb128(localidx_);
}
} // namespace antiwasm
