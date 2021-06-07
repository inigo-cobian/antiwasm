#include "end.hpp"

namespace antiwasm {
EndInstr::EndInstr() {
  instructionCode = End;
  nBytes = 1;
}
} // namespace antiwasm