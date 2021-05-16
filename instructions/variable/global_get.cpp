#include "global_get.hpp"

namespace antiwasm {
GlobalGet::GlobalGet(const uint8_t *globalIdx_) {
  instructionCode = Global_get;
  globalIdx = transformLeb128ToUnsignedInt32(globalIdx_);
  nBytes = 1 + sizeOfLeb128(globalIdx_);
}
} // namespace antiwasm