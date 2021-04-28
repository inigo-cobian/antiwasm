#include "globaltype.hpp"

namespace antiwasm {
Globaltype parseGlobaltype(const uint8_t *globaltypeContent) {
  Globaltype globaltype{};
  globaltype.valtype = parseValtype(globaltypeContent[0]);
  if (globaltype.valtype.hasError()) {
    auto error = generateError(fatal, unrecognizedValtypeAtGlobaltype, 0);
    globaltype.addError(error);
    return globaltype;
  }
  globaltype.mut = parseMut(globaltypeContent[1]);
  if (globaltype.mut == invalid_mut) {
    auto error = generateError(fatal, unrecognizedMutAtGlobaltype, 0);
    globaltype.addError(error);
  }
  return globaltype;
}

string Globaltype::getAsText() const {
  stringstream globalAsText;
  globalAsText << "( global (" ;
  if(mut == var_) {
    globalAsText << "mut ";
  } // constants are implicit
  globalAsText << valtype.getAsText() << " ) )";

  return globalAsText.str();
}
} // namespace antiwasm
