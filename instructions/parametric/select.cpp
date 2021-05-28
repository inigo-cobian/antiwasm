#include "select.hpp"

namespace antiwasm {
SelectInstr::SelectInstr() {
  instructionCode = InstructionSet::Select;
  nBytes = 1;
}
} // namespace antiwasm