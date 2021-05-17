#include "i64_arithmetic.hpp"

namespace antiwasm {
I64Arithmetic::I64Arithmetic(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm