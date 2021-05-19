#include "data_drop.hpp"

namespace antiwasm {
DataDrop::DataDrop(const uint8_t * instrContent) {
  instructionCode = double_byte_instr;
  secondCode = Data_drop;
  dataidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm
