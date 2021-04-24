#include "import.hpp"

namespace antiwasm {
Import parseImport(const uint8_t *importContent) {
  // TODO mod name importdesc
  switch (importContent[0]) {
  case ImportFunc:
    break;
  case ImportTable:
    break;
  case ImportMemtype:
    break;
  case ImportGlobaltype:
    break;
  default:
    // TODO error
    break;
  }
  return Import{};
}
} // namespace antiwasm