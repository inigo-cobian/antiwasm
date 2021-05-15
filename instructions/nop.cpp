#include "nop.hpp"

namespace antiwasm {
NopInstr::NopInstr() {
  instructionCode = Nop;
  nBytes = 1;
}
} // namespace antiwasm