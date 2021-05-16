#include "data_drop.hpp"

namespace antiwasm {
DataDrop::DataDrop(const uint8_t * dataidx_) {
  instructionCode = double_byte_instr;
  secondCode = Data_drop;
  dataidx = transformLeb128ToUnsignedInt32(dataidx_);
  nBytes = 1 + sizeOfLeb128(dataidx_);
}
} // namespace antiwasm
