#include "extension.hpp"

namespace antiwasm {
ExtensionInstr::ExtensionInstr(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm