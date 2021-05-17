#include "i32_arithmetic.hpp"

namespace antiwasm {
I32Arithmetic::I32Arithmetic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm