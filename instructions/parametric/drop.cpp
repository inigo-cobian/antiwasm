#include "drop.hpp"

namespace antiwasm {
DropInstr::DropInstr() {
  instructionCode = InstructionSet::Drop;
  nBytes = 1;
}
} // namespace antiwasm