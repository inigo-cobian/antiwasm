#include "elem_drop.hpp"

namespace antiwasm {
ElemDrop::ElemDrop(const uint8_t *instructionContent) {
  instructionCode = double_byte_instr;
  secondCode = Elem_drop;
  tableidx = transformLeb128ToUnsignedInt32(instructionContent + 2);
  nBytes = 2 + sizeOfLeb128(instructionContent + 2);
}
} // namespace antiwasm