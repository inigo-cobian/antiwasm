#include "tabletype.hpp"

namespace antiwasm {
Tabletype parseTableType(const uint8_t *tableTypeContent) {
  Reftype reftypeAtTabletype = parseReftype(tableTypeContent[0]);
  Limit limitAtTabletype = parseLimits(&tableTypeContent[1]);
  Tabletype tabletype{reftypeAtTabletype, limitAtTabletype};

  if (reftypeAtTabletype == invalid_reftype) {
    std::cout << "Error at reftype" << std::endl;
    auto error = generateError(fatal, unrecognizedReftypeAtTabletype, 0);
    tabletype.addError(error);
    return tabletype;
  }

  if (limitAtTabletype.hasError()) {
    std::cout << "Error at limit" << std::endl;
    auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, 0);
    tabletype.addError(error);
  }

  return tabletype;
}

void Tabletype::displayContentInfo() {
  if (hasError()) {
    std::cout << "Error at tabletype" << std::endl;
    // TODO error
    displayError();
  }
  std::cout << "    [";
  displayReftype(reftype);
  std::cout << "] ";
  limit.displayContentInfo();
  std::cout << std::endl;
}

void Tabletype::displayError() {
  // TODO
}
} // namespace antiwasm
