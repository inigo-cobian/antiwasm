#include "call.hpp"

namespace antiwasm {
CallInstr::CallInstr(const uint8_t *instrContent) {
  instructionCode = Call;
  funcidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm