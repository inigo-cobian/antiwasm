#include "import.hpp"

namespace antiwasm {
Import parseImport(const uint8_t *importContent) {
  // Parse mod as UTF8
  auto sizeOfMod = transformLeb128ToUnsignedInt32(importContent);
  size_t pointer = sizeOfLeb128(importContent);
  auto mod = parseUTF8Name(&importContent[pointer], sizeOfMod);
  pointer += sizeOfMod;
  BOOST_LOG_TRIVIAL(debug) << "[Import] Mod: " << mod.name;

  // Parse name as UTF8
  auto sizeOfName = transformLeb128ToUnsignedInt32(&importContent[pointer]);
  pointer += sizeOfLeb128(importContent);
  auto indexName = pointer;
  auto name = parseUTF8Name(&importContent[pointer], sizeOfName);
  pointer += sizeOfName;
  BOOST_LOG_TRIVIAL(debug) << "[Import] Name: " << name.name;

  auto indexImportDesc = pointer;
  auto type = parseImportDescType(importContent[pointer]);
  pointer++;
  BOOST_LOG_TRIVIAL(debug) << "[Import] type: " << type;

  Import import{mod, name};

  import.setNBytes(pointer);

  import.addImportDesc(type, importContent);

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
    break;
  case ImportMemtype:
    if (import.importDesc.memtype->hasError()) {
      auto error = generateError(fatal, unrecognizedMemtypeAtImportDesc, indexImportDesc);
      import.addError(error);
    }
    break;
  case ImportGlobaltype:
    if (import.importDesc.globaltype->hasError()) {
      auto error = generateError(fatal, unrecognizedGlobaltypeAtImportDesc, indexImportDesc);
      import.addError(error);
    }
    break;
  case invalidImportDescType:
    auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, indexImportDesc);
    import.addError(error);
  }

  cout << "[Import] nBytes: " << import.getNBytes();

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
    BOOST_LOG_TRIVIAL(debug) << "[Import] Unrecognized: " << hex << (int)importDescTypeContent;
    return invalidImportDescType;
  }
}

void Import::addImportDesc(ImportDescType type, const uint8_t *importDescContent) {
  switch (type) {
  case ImportFunc: {
    importDesc.typeIdx = transformLeb128ToUnsignedInt32(importDescContent);
    setNBytes(getNBytes() + sizeOfLeb128(importDescContent));
  } break;
  case ImportTable: { // TODO explain that the braces are to avoid crosses initialization of
    auto tabletype = parseTableType(importDescContent);
    importDesc.tabletype = new Tabletype(tabletype);
    setNBytes(getNBytes() + importDesc.tabletype->getNBytes());
  } break;
  case ImportMemtype: {
    auto memtype = parseMemType(importDescContent);
    importDesc.memtype = new Memtype(memtype);
    setNBytes(getNBytes() + importDesc.memtype->getNBytes());
  } break;
  case ImportGlobaltype: {
    auto globaltype = parseGlobaltype(importDescContent);
    importDesc.globaltype = new Globaltype(globaltype);
    setNBytes(getNBytes() + importDesc.globaltype->getNBytes());
  } break;
  }
}

} // namespace antiwasm