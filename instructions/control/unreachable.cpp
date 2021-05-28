#include "unreachable.hpp"

namespace antiwasm {
UnreachableInstr::UnreachableInstr() {
  instructionCode = Unreachable;
  nBytes = 1;
}
} // namespace antiwasm