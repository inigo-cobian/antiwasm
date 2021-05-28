#include "br_if.hpp"

namespace antiwasm {
BrIfInstr::BrIfInstr(const uint8_t *instrContent) {
  instructionCode = Br_if;
  labelidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm