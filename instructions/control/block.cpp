#include "block.hpp"

namespace antiwasm {
BlockInstr::BlockInstr(const uint8_t *instrContent) {
  instructionCode = Block;
  blocktype = parseBlocktype(instrContent);

  auto pos = blocktype.getNBytes();
  uint32_t nBytes_ = 0;
  instructionSet = parseInstructionSet(instrContent + pos, nBytes_);
  nBytes = nBytes_;
}
} // namespace antiwasm