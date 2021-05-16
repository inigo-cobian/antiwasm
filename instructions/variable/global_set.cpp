#include "global_set.hpp"

namespace antiwasm {
GlobalSet::GlobalSet(const uint8_t *globalIdx_) {
  instructionCode = Global_set;
  globalIdx = transformLeb128ToUnsignedInt32(globalIdx_);
  nBytes = 1 + sizeOfLeb128(globalIdx_);
}
} // namespace antiwasm
