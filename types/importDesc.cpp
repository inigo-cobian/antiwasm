#include "importDesc.hpp"

namespace antiwasm {
ImportDesc parseImportDesc(const uint8_t *importDescContent) { // TODO
  switch (importDescContent[0]) {
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
  return ImportDesc{};
}
} // namespace antiwasm