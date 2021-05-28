#include "if.hpp"

namespace antiwasm {
IfInstr::IfInstr(const uint8_t *instrContent) {
  instructionCode = If;
  blocktype = parseBlocktype(instrContent);

  auto pos = blocktype.getNBytes();
  uint32_t nBytes_ = 0;
  instructionSet = parseIfInstructionSet(instrContent + pos, nBytes_);
  nBytes = nBytes_;
}
} // namespace antiwasm