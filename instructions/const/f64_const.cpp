#include "f64_const.hpp"

namespace antiwasm {
:F64Const::F64Const(const uint8_t *f64Const) {
  instructionCode = f64_const;
  constant = transformf64ToDouble(f64Const);
  nBytes = 9; // Instruction code + size of f64
}
}
