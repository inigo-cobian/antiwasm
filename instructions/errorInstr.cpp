#include "errorInstr.hpp"

namespace antiwasm {
ErrorInstr::ErrorInstr(const uint8_t *instrContent) {
  instructionCode = error_instr;

  if (instrContent[0] == double_byte_instr) {

    auto error = generateError(fatal, unrecognizedDoubleByteInstruction, 1);
    addError(error);
    invalidInstrByte = instrContent[1];
    nBytes = 2;
  }
  else if(instrContent[0] == Else ) {
    auto error = generateError(fatal, unlinkedElseAtInstruction, 0);
    addError(error);
    invalidInstrByte = instrContent[0];
    nBytes = 1;
  }
  else {
    auto error = generateError(fatal, unrecognizedInstruction, 0);
    addError(error);
    invalidInstrByte = instrContent[0];
    nBytes = 1;
  }
}
uint8_t ErrorInstr::getInvalidInstrByte() const { return invalidInstrByte; }
} // namespace antiwasm