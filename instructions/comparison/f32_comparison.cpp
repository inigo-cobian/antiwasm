#include "f32_comparison.hpp"

namespace antiwasm {
F32Comp::F32Comp(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm