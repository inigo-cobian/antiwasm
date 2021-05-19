#include "local_get.hpp"

namespace antiwasm {
antiwasm::LocalGet::LocalGet(const uint8_t *instrContent) {
  instructionCode = Local_get;
  localidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm
