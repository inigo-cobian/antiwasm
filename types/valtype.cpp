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

void displayValtype(Valtype valtype) {
  if (valtype.type == valtype_numtype) {
    displayNumtype(valtype.numtype);
  } else if (valtype.type == valtype_reftype) {
    displayReftype(valtype.reftype);
  } else {
    std::cout << "Error at valtype" << std::endl;
  }
}
} // namespace antiwasm
