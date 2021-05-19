#include "ref_func.hpp"

namespace antiwasm {
RefFunc::RefFunc(const uint8_t *instrContent) {
  instructionCode = (InstructionSet)instrContent[0];
  funcidx = transformLeb128ToUnsignedInt32(instrContent + 1);
  nBytes = 1 + sizeOfLeb128(instrContent + 1);
}
} // namespace antiwasm
