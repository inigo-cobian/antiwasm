#include "f32_arithmetic.hpp"

namespace antiwasm {
F32Arithmetic::F32Arithmetic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm