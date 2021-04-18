#include "tabletype.hpp"

namespace antiwasm {
Tabletype parseTableType(const uint8_t *tableTypeContent) {
  Reftype reftypeAtTabletype = parseReftype(tableTypeContent[0]);
  Limit limitAtTabletype = parseLimits(&tableTypeContent[1]);
  Tabletype tabletype{reftypeAtTabletype, limitAtTabletype};

  if (reftypeAtTabletype == invalid_reftype) {
    cout << "Error at reftype" << endl;
    auto error = generateError(fatal, unrecognizedReftypeAtTabletype, 0);
    tabletype.addError(error);
    return tabletype;
  }

  if (limitAtTabletype.hasError()) {
    cout << "Error at limit" << endl;
    auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, 0);
    tabletype.addError(error);
  }

  return tabletype;
}

void Tabletype::displayContentInfo() {
  if (hasError()) {
    cout << "Error at tabletype" << endl;
    // TODO error
    displayError();
  }
  cout << "    [";
  displayReftype(reftype);
  cout << "] ";
  limit.displayContentInfo();
  cout << endl;
}

void Tabletype::displayError() {
  // TODO
}
} // namespace antiwasm
