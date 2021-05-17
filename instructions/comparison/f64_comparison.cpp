#include "f64_comparison.hpp"

namespace antiwasm {
F64Comp::F64Comp(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm