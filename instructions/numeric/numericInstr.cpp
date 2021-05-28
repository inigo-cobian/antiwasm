#include "numericInstr.hpp"

namespace antiwasm {
NumericInstr::NumericInstr(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm