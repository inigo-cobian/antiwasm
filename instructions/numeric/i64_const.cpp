#include "i64_const.hpp"

namespace antiwasm {
I64Const::I64Const(const uint8_t *instrContent) {
  instructionCode = i64_const;
  constant = transformLeb128ToSignedInt64(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
  BOOST_LOG_TRIVIAL(debug) << "[I64Const] Value of i64.const: " << constant;
}
} // namespace antiwasm
