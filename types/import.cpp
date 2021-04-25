#include "import.hpp"

namespace antiwasm {
Import parseImport(const uint8_t *importContent) {
  // Parse mod as UTF8
  auto sizeOfMod = transformLeb128ToUnsignedInt32(importContent);
  size_t pointer = sizeOfLeb128(importContent);
  auto mod = parseUTF8Name(&importContent[pointer], sizeOfMod);
  pointer += sizeOfMod;

  // Parse name as UTF8
  auto sizeOfName = transformLeb128ToUnsignedInt32(&importContent[pointer]);
  pointer += sizeOfLeb128(importContent);
  auto name = parseUTF8Name(&importContent[pointer], sizeOfName);

  auto type = ImportDescType::ImportFunc; // TODO
  auto desc = parseImportDesc(type, importContent); // TODO

  Import import{mod, name, type, desc };

  if(mod.hasError()) {
    auto error = generateError(fatal, unrecognizedModAtImport, 0);
    import.addError(error);
  }

  if(name.hasError()) {
    auto error = generateError(fatal, unrecognizedNameAtImport, 1);
    import.addError(error);
  }

  // TODO error for ImportDesc

  return import;
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