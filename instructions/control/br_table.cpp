#include "br_table.hpp"

namespace antiwasm {
BrTableInstr::BrTableInstr(const uint8_t *instrContent) {
  instructionCode = Br_table;
  auto labelidxVecSize = sizeOfLeb128(instrContent + 1);
  uint32_t pos = 2;
  nBytes = 2;

  for (uint32_t i = 0; i < labelidxVecSize; i++) {
    labelidxVec.push_back(transformLeb128ToUnsignedInt32(instrContent + pos));
    pos += sizeOfLeb128(instrContent + pos);
    nBytes += sizeOfLeb128(instrContent + pos);
  }

  labelidx = transformLeb128ToUnsignedInt32(instrContent + pos);
  nBytes += sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm