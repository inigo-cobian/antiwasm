#include "resulttype.hpp"

namespace antiwasm {
Resulttype parseResulttype(const uint8_t *resultTypeContent) {
  Resulttype resulttype;
  auto elementsInResulttype = transformLeb128ToUnsignedInt32(resultTypeContent);
  auto pointer = sizeOfLeb128(resultTypeContent);
  for (auto i = 0; i < elementsInResulttype; i++) {
    auto elementType = resultTypeContent[pointer];
    Valtype valtype = parseValtype(elementType);
    resulttype.valtypeVector.push_back(valtype);
    if (valtype.error) {
      resulttype.error = true;
    }
    pointer++;
  }
  resulttype.nBytes = sizeOfLeb128(resultTypeContent) + elementsInResulttype;
  return resulttype;
}

void displayResulttype(const Resulttype &resulttype) {
  std::cout << "    Resulttype[";
  for (auto valtype : resulttype.valtypeVector) {
    displayValtype(valtype);
    std::cout << "-";
  }
  std::cout << "]" << std::endl;
}
} // namespace antiwasm
