#include "i32_const.hpp"

namespace antiwasm {
I32Const::I32Const(const uint8_t *i32Const) {
  instructionCode = i32_const;
  constant = transformLeb128ToSignedInt32(i32Const);
  nBytes = 1 + sizeOfLeb128(i32Const);
}
} // namespace antiwasm
