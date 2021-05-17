#include "i32_comparison.hpp"

namespace antiwasm {
I32Comp::I32Comp(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm