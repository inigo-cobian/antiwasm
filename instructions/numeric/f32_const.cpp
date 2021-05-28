#include "f32_const.hpp"

namespace antiwasm {
F32Const::F32Const(const uint8_t *instrContent) {
  instructionCode = f32_const;
  constant = transformf32ToFloat(instrContent + 1);
  nBytes = 5; // Instruction code + size of f32
}
} // namespace antiwasm