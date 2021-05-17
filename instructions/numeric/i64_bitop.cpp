#include "i64_bitop.hpp"

namespace antiwasm {
I64BitOp::I64BitOp(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm