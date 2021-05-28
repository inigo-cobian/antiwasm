#include "else.hpp"

namespace antiwasm {
ElseInstr::ElseInstr(const uint8_t *instrContent) {
  instructionCode = Else;
  blocktype = parseBlocktype(instrContent);

  auto pos = blocktype.getNBytes();
  uint32_t nBytes_ = 0;
  instructionSet = parseInstructionSet(instrContent + pos, nBytes_);
  nBytes = nBytes_;
}
} // namespace antiwasm