#include "tabletype.hpp"

namespace antiwasm {
Tabletype parseTableType(const uint8_t *tableTypeContent) {
  Reftype reftypeAtTabletype = parseReftype(tableTypeContent[0]);
  Limit limitAtTabletype = parseLimits(&tableTypeContent[1]);
  Tabletype tabletype{reftypeAtTabletype, limitAtTabletype};

  if (reftypeAtTabletype == invalid_reftype) {
    std::cout << "Error at reftype" << std::endl;
    tabletype.error = true;
    return tabletype;
  }

  if (limitAtTabletype.hasError()) {
    std::cout << "Error at limit" << std::endl;
    tabletype.error = true;
  }

  return tabletype;
}

void displayTabletype(Tabletype tabletype) {
  if (tabletype.error) {
    std::cout << "Error at tabletype" << std::endl;
    // TODO error
  }
  std::cout << "    [";
  displayReftype(tabletype.reftype);
  std::cout << "] ";
  displayLimits(tabletype.limit);
  std::cout << std::endl;
}
} // namespace antiwasm
