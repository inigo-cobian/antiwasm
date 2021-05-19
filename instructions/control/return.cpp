#include "return.hpp"

namespace antiwasm {
ReturnInstr::ReturnInstr() {
  instructionCode = Return;
  nBytes = 1;
}
} // namespace antiwasm