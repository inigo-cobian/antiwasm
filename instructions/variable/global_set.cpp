#include "global_set.hpp"

namespace antiwasm {
GlobalSet::GlobalSet(const uint8_t *instrContent) {
  instructionCode = Global_set;
  globalIdx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm
