#include "i64_comparison.hpp"

namespace antiwasm {
I64Comp::I64Comp(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm