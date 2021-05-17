#include "i64_logic.hpp"

namespace antiwasm {
I64Logic::I64Logic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm