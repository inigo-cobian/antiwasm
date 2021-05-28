#include "local_tee.hpp"

namespace antiwasm {
LocalTee::LocalTee(const uint8_t *instrContent) {
  instructionCode = Local_tee;
  localidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm