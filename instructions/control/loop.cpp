#include "loop.hpp"

namespace antiwasm {
LoopInstr::LoopInstr(const uint8_t *instrContent) {
  instructionCode = Loop;
  blocktype = parseBlocktype(instrContent);

  auto pos = blocktype.getNBytes();
  uint32_t nBytes_ = 0;
  instructionSet = parseInstructionSet(instrContent + pos, nBytes_);
  nBytes = nBytes_;
}
} // namespace antiwasm