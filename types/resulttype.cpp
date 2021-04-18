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
    if (valtype.hasError()) {
      auto error = generateError(fatal, unrecognizedValtypeAtResulttype, resulttype.valtypeVector.size());
      resulttype.addError(error);
    }
    pointer++;
  }
  resulttype.nBytes = sizeOfLeb128(resultTypeContent) + elementsInResulttype;
  return resulttype;
}

void Resulttype::displayContentInfo() {
  cout << "    Resulttype[";
  for (auto valtype : valtypeVector) {
    valtype.displayContentInfo();
    cout << "-";
  }
  cout << "]" << endl;
}

void Resulttype::displayError() {
  // TODO
}

} // namespace antiwasm
