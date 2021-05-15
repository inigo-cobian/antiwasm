#include "i64_const.hpp"

namespace antiwasm {
I64Const::I64Const(const uint8_t *i64Const) {
  instructionCode = i64_const;
  constant = transformLeb128ToSignedInt64(i64Const);
  nBytes = 1 + sizeOfLeb128(i64Const);
}
