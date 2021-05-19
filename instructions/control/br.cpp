#include "br.hpp"

namespace antiwasm {
BrInstr::BrInstr(const uint8_t *instrContent) {
  instructionCode = Br;
  labelidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm