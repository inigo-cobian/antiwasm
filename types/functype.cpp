#include "functype.hpp"

namespace antiwasm {

Functype parseFunctype(const uint8_t *funcTypeContent) {
  Functype functype;
  if (funcTypeContent[0] != FUNCTYPE_HEADER) {
    functype.error = true;
    std::cout << "Functype header not found: " << std::hex << (int)funcTypeContent[0] << std::endl;
    return functype;
  }

  functype.parameterType = parseResulttype(&funcTypeContent[BYTES_HEADER_FUNCTYPE]);
  if (functype.parameterType.error) {
    functype.error = true;
    std::cout << "Error at functype.parameterType" << std::endl;
    return functype;
  }
  auto indexReturnType = BYTES_HEADER_FUNCTYPE + functype.parameterType.nBytes;
  functype.returnType = parseResulttype(&funcTypeContent[indexReturnType]);
  if (functype.returnType.error) {
    functype.error = true;
    std::cout << "Error at functype.returnType" << std::endl;
  }
  functype.nBytes = BYTES_HEADER_FUNCTYPE + functype.parameterType.nBytes + functype.returnType.nBytes;

  return functype;
}

void displayFunctype(Functype functype) {
  if (functype.error) {
    std::cout << "Error at current functype" << std::endl;
    return;
  }

  std::cout << "  Functype (rt1):" << std::endl;
  displayResulttype(functype.parameterType);

  std::cout << "  Functype (rt2):" << std::endl;
  displayResulttype(functype.returnType);
}

} // namespace antiwasm