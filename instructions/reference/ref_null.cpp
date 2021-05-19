#include "ref_null.hpp"

namespace antiwasm {
RefNull::RefNull(const uint8_t *instrContent) {
  instructionCode = (InstructionSet)instrContent[0];
  reftype = parseReftype(instrContent[1]);
  nBytes = 2;
}
} // namespace antiwasm
