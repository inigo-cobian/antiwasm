#include "i32_bitop.hpp"

namespace antiwasm {
I32BitOp::I32BitOp(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm