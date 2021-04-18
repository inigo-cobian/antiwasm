#include "functype.hpp"

namespace antiwasm {

Functype parseFunctype(const uint8_t *funcTypeContent) {
  Functype functype;
  if (funcTypeContent[0] != FUNCTYPE_HEADER) {
    auto error = generateError(fatal, unrecognizedHeaderAtFunctype, 0);
    functype.addError(error);
    std::cout << "Functype header not found: " << std::hex << (unsigned int)funcTypeContent[0] << std::endl;
    return functype;
  }

  functype.parameterType = parseResulttype(&funcTypeContent[BYTES_HEADER_FUNCTYPE]);
  if (functype.parameterType.hasError()) {
    auto error = generateError(fatal, unrecognizedRT1Functype, 0);
    functype.addError(error);
    std::cout << "Error at functype.parameterType" << std::endl;
    return functype;
  }
  auto indexReturnType = BYTES_HEADER_FUNCTYPE + functype.parameterType.nBytes;
  functype.returnType = parseResulttype(&funcTypeContent[indexReturnType]);
  if (functype.returnType.hasError()) {
    auto error = generateError(fatal, unrecognizedRT2Functype, 0);
    functype.addError(error);
    std::cout << "Error at functype.returnType" << std::endl;
  }
  functype.nBytes = BYTES_HEADER_FUNCTYPE + functype.parameterType.nBytes + functype.returnType.nBytes;

  return functype;
}

void Functype::displayContentInfo() {
  if (hasError()) {
    std::cout << "Error at current functype" << std::endl;
    return;
  }

  std::cout << "  Functype (rt1):" << std::endl;
  parameterType.displayContentInfo();

  std::cout << "  Functype (rt2):" << std::endl;
  returnType.displayContentInfo();
}

void Functype::displayError() {
  // TODO
}
} // namespace antiwasm