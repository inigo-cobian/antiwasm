#include "i32_const.hpp"

namespace antiwasm {
I32Const::I32Const(const uint8_t *instrContent) {
  instructionCode = i32_const;
  constant = transformLeb128ToSignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
  BOOST_LOG_TRIVIAL(debug) << "[I32Const] Value of i32.const: " << constant;
}
} // namespace antiwasm
