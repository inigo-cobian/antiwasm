#include "functype.hpp"

namespace antiwasm {

Functype parseFunctype(const uint8_t *funcTypeContent) {
  Functype functype;
  if (funcTypeContent[0] != FUNCTYPE_HEADER) {
    auto error = generateError(fatal, unrecognizedHeaderAtFunctype, 0);
    functype.addError(error);
    cout << "Functype header not found: " << hex << (unsigned int)funcTypeContent[0] << endl;
    return functype;
  }

  functype.parameterType = parseResulttype(&funcTypeContent[BYTES_HEADER_FUNCTYPE]);
  if (functype.parameterType.hasError()) {
    auto error = generateError(fatal, unrecognizedRT1Functype, 0);
    functype.addError(error);
    cout << "Error at functype.parameterType" << endl;
    return functype;
  }
  auto indexReturnType = BYTES_HEADER_FUNCTYPE + functype.parameterType.nBytes;
  functype.returnType = parseResulttype(&funcTypeContent[indexReturnType]);
  if (functype.returnType.hasError()) {
    auto error = generateError(fatal, unrecognizedRT2Functype, 0);
    functype.addError(error);
    cout << "Error at functype.returnType" << endl;
  }
  functype.nBytes = BYTES_HEADER_FUNCTYPE + functype.parameterType.nBytes + functype.returnType.nBytes;

  return functype;
}
} // namespace antiwasm