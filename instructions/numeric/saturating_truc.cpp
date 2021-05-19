#include "saturating_truc.hpp"

namespace antiwasm {
SaturatingTrunc::SaturatingTrunc(const uint8_t *content) {
  instructionCode = double_byte_instr;
  secondCode = static_cast<SecondByteSet>(content[0]);
  nBytes = 2;
}
} // namespace antiwasm