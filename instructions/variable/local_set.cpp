#include "local_set.hpp"

namespace antiwasm {
LocalSet::LocalSet(const uint8_t *instrContent) {
instructionCode = Local_set;
localidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm