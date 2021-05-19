#include "f64_const.hpp"

namespace antiwasm {
F64Const::F64Const(const uint8_t *instrContent) {
  instructionCode = f64_const;
  constant = transformf64ToDouble(instrContent + 1);
  nBytes = 9; // Instruction code + size of f64
}
} // namespace antiwasm
