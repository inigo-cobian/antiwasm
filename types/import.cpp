#include "import.hpp"

namespace antiwasm {

Import::Import(UTF8Name p_module, UTF8Name p_name, ImportDescType p_importDescType, ImportDesc p_importDesc)
    : module(std::move(p_module)), name(std::move(p_name)), importDescType(p_importDescType), importDesc(p_importDesc) {
  nBytes = module.getNBytes() + name.getNBytes();
  switch (importDescType) {
  case ImportFunc:
    nBytes += 2; // TODO get size of index
    break;
  case ImportTable:
    nBytes += importDesc.tabletype->getNBytes();
    break;
  case ImportMemtype:
    nBytes += importDesc.memtype->getNBytes();
    break;
  case ImportGlobaltype:
    nBytes += importDesc.globaltype->getNBytes();
    break;
  }
}

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

  ImportDesc desc = parseImportDesc(type, &importContent[pointer]);

  Import import(mod, name, type, desc);

  if (mod.hasError()) {
    BOOST_LOG_TRIVIAL(error) << "[Import] Error: unrecognizedModAtImport";
    auto error = generateError(warning, unrecognizedModAtImport, 0);
    import.addError(error);
  }

  if (name.hasError()) {
    BOOST_LOG_TRIVIAL(error) << "[Import] Error: unrecognizedModAtImport";
    auto error = generateError(warning, unrecognizedNameAtImport, indexName);
    import.addError(error);
  }

  if (type == invalidImportDescType) {
    auto error = generateError(fatal, unrecognizedHeaderAtImportDesc, indexName);
    import.addError(error);
    return import;
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
  }

  BOOST_LOG_TRIVIAL(debug) << "[Import] nBytes: " << import.getNBytes();

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
    BOOST_LOG_TRIVIAL(debug) << "[Import] Unrecognized: " << std::hex << (int)importDescTypeContent;
    return invalidImportDescType;
  }
}

ImportDesc parseImportDesc(ImportDescType type, const uint8_t *importDescContent) {
  ImportDesc importDesc;
  switch (type) {
  case ImportFunc: {
    importDesc.typeIdx = transformLeb128ToUnsignedInt32(importDescContent);
    // TODO nBytes
    return importDesc;
  }
  case ImportTable: { // TODO explain that the braces are to avoid crosses initialization of union
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
  default:
    BOOST_LOG_TRIVIAL(error) << "[Import] Failing to create an Import desc as there is no valid header";
    return importDesc;
  }
}

} // namespace antiwasm
