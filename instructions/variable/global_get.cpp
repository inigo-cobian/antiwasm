#include "global_get.hpp"

namespace antiwasm {
GlobalGet::GlobalGet(const uint8_t *instrContent) {
  instructionCode = Global_get;
  globalIdx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm