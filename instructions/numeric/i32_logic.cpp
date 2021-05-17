#include "i32_logic.hpp"

namespace antiwasm {
I32Logic::I32Logic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm