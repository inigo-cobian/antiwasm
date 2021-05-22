#include "load.hpp"

namespace antiwasm {
LoadInstr::LoadInstr(const uint8_t *loadInstrContent) : memArg(parseMemArg(loadInstrContent + 1)) {
  instructionCode = (InstructionSet)loadInstrContent[0];
  nBytes = memArg.getNBytes() + 1;
}
} // namespace antiwasm
