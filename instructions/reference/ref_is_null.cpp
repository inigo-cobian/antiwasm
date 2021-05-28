#include "ref_is_null.hpp"

namespace antiwasm {
RefIsNull::RefIsNull(const uint8_t *instrContent) {
  instructionCode = (InstructionSet)instrContent[0];
  nBytes = 1;
}
} // namespace antiwasm
