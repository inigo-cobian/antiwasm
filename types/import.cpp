#include "import.hpp"

namespace antiwasm {
Import parseImport(const uint8_t *importContent) {
  // TODO mod module importdesc
  auto mod = UTF8Name{};
  auto name = UTF8Name{};
  auto type = ImportDescType::ImportFunc; // TODO
  auto desc = parseImportDesc(type, importContent);
  return Import{mod, name, type, desc };
}


ImportDesc parseImportDesc(ImportDescType type, const uint8_t *importDescContent) {
  ImportDesc importDesc;
  switch (0) { // TODO
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