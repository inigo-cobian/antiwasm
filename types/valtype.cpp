#include "valtype.hpp"

namespace antiwasm {
Valtype parseValtype(const uint8_t valtypeContent) {
  Valtype valtype;
  if (valtypeContent <= i32 && valtypeContent >= f64) {
    valtype.type = valtype_numtype;
    valtype.numtype = parseNumType(valtypeContent);
  } else if (valtypeContent == funref || valtypeContent == externref) {
    valtype.type = valtype_reftype;
    valtype.reftype = parseReftype(valtypeContent);
  } else {
    valtype.type = valtype_error;
    auto error = generateError(fatal, unrecognizedValtype, 0);
    valtype.addError(error);
  }
  return valtype;
}

void Valtype::displayContentInfo() {
  if (type == valtype_numtype) {
    displayNumtype(numtype);
  } else if (type == valtype_reftype) {
    displayReftype(reftype);
  } else {
    displayError();
  }
}

void Valtype::displayError() {
  // TODO
  std::cout << "UndefinedSectionId at valtype" << std::endl;
}
std::string Valtype::getAsText() const {
  if (type == valtype_numtype) {
    return getNumtypeAsText(numtype);
  } else if (type == valtype_reftype) {
    return getReftypeAsText(reftype);
  } else {
    return "error.valtype";
  }
}
} // namespace antiwasm
