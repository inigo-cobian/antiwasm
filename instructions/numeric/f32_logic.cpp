#include "f32_logic.hpp"

namespace antiwasm {
F32Logic::F32Logic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm