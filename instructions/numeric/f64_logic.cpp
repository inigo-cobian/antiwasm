#include "f64_logic.hpp"

namespace antiwasm {
F64Logic::F64Logic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm