#include "globaltype.hpp"

#include <utility>

namespace antiwasm {
Globaltype::Globaltype(Valtype valtype_, Mut mut_) : valtype(std::move(valtype_)), mut(mut_) {
  nBytes = BYTES_GLOBALTYPE;
}

Globaltype parseGlobaltype(const uint8_t *globaltypeContent) {
  auto valtype = parseValtype(globaltypeContent[0]);
  auto mut = parseMut(globaltypeContent[1]);

  Globaltype globaltype{valtype, mut};

  if (valtype.hasError()) {
    auto error = generateError(fatal, unrecognizedValtypeAtGlobaltype, 0);
    globaltype.addError(error);
    return globaltype;
  }

  if (mut == invalid_mut) {
    auto error = generateError(fatal, unrecognizedMutAtGlobaltype, 0);
    globaltype.addError(error);
  }

  return globaltype;
}

std::string Globaltype::getAsText() const {
  std::stringstream globalAsText;
  globalAsText << "( global ( ";
  if (mut == var_) {
    globalAsText << "mut ";
  } // constants are implicit
  globalAsText << valtype.getAsText() << " ) )";

  return globalAsText.str();
}
} // namespace antiwasm
