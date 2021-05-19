#include "call_indirect.hpp"

namespace antiwasm {
CallIndirectInstr::CallIndirectInstr(const uint8_t *instrContent) {
  instructionCode = Call_indirect;
  typeidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
  tableidx = transformLeb128ToUnsignedInt32(instrContent + nBytes);
  nBytes = sizeOfLeb128(instrContent + nBytes);
}
} // namespace antiwasm
