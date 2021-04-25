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
  auto indexName = pointer;
  auto name = parseUTF8Name(&importContent[pointer], sizeOfName);
  pointer += sizeOfName;

  auto indexImportDesc = pointer;
  auto type = parseImportDescType(importContent[pointer]);

  auto desc = parseImportDesc(type, importContent);

  Import import{mod, name, type, desc};

  if (mod.hasError()) {
    auto error = generateError(fatal, unrecognizedModAtImport, 0);
    import.addError(error);
  }

  if (name.hasError()) {
    auto error = generateError(fatal, unrecognizedNameAtImport, indexName);
    import.addError(error);
  }

  switch (type) {
    // Case ImportFunc cannot be incorrect at this stage
  case ImportTable:
    if (import.importDesc.tabletype->hasError()) {
      auto error = generateError(fatal, unrecognizedTabletypeAtImportDesc, indexImportDesc);
      import.addError(error);
    }
  case ImportMemtype:
    if (import.importDesc.memtype->hasError()) {
      auto error = generateError(fatal, unrecognizedMemtypeAtImportDesc, indexImportDesc);
      import.addError(error);
    }
  case ImportGlobaltype:
    if (import.importDesc.globaltype->hasError()) {
      auto error = generateError(fatal, unrecognizedGlobaltypeAtImportDesc, indexImportDesc);
      import.addError(error);
    }
  case invalidImportDescType:
    auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, indexImportDesc);
    import.addError(error);
  }

  return import;
}

ImportDescType parseImportDescType(const uint8_t importDescTypeContent) {
  switch (importDescTypeContent) {
  case ImportFunc:
    return ImportFunc;
  case ImportTable:
    return ImportTable;
  case ImportMemtype:
    return ImportMemtype;
  case ImportGlobaltype:
    return ImportGlobaltype;
  default:
    return invalidImportDescType;
  }
}

ImportDesc parseImportDesc(ImportDescType type, const uint8_t *importDescContent) {
  ImportDesc importDesc{};
  switch (type) {
  case ImportFunc: {
    importDesc.typeIdx = transformLeb128ToUnsignedInt32(importDescContent);
    return importDesc;
  }
  case ImportTable: { // TODO explain that the braces are to avoid crosses initialization of
    auto tabletype = parseTableType(importDescContent);
    importDesc.tabletype = new Tabletype(tabletype);
    return importDesc;
  }
  case ImportMemtype: {
    auto memtype = parseMemType(importDescContent);
    importDesc.memtype = new Memtype(memtype);
    return importDesc;
  }
  case ImportGlobaltype: {
    auto globaltype = parseGlobaltype(importDescContent);
    importDesc.globaltype = new Globaltype(globaltype);
    return importDesc;
  }
  case invalidImportDescType:
    return importDesc; // Unused
  }
}
} // namespace antiwasm