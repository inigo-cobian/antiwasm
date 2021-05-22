#include "select_vecValtype.hpp"

namespace antiwasm {
SelectValtypeInstr::SelectValtypeInstr(const uint8_t *instrContent) {
  instructionCode = Select_vecValtype;
  auto vecSize = transformLeb128ToUnsignedInt32(instrContent + 1);
  auto pos = sizeOfLeb128(instrContent + 1) + 1;

  for(uint32_t i = 0; i < vecSize; i++) {
    auto valtype = parseValtype(instrContent[pos]);
    valtypeVec.push_back(valtype);

    if(valtype.hasError()) {
      auto error = generateError(fatal, unrecognizedValtypeAtSelectInstr, valtypeVec.size());
      addError(error);
      break;
    }
    pos++;
  }

  nBytes = pos;
}
} // namespace antiwasm
