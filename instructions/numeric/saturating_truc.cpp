#include "saturating_truc.hpp"

namespace antiwasm {
SaturatingTrunc::SaturatingTrunc(const uint8_t *instrContent) {
  instructionCode = double_byte_instr;
  secondCode = static_cast<SecondByteSet>(instrContent[1]);
  nBytes = 2;
}
} // namespace antiwasm