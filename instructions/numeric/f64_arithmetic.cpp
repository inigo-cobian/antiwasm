#include "f64_arithmetic.hpp"

namespace antiwasm {
F64Arithmetic::F64Arithmetic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm