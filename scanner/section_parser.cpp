#include "section_parser.hpp"

using namespace std;
namespace antiwasm {

Section parseNextSection(uint8_t sectionId, int sectionSize, uint8_t *sectionContent, int sectionPos) {

  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Info of the next section [" << hex << (unsigned int)sectionId
                           << "] with size " << hex << (unsigned int)sectionSize;
  switch (sectionId) {
  case (SectionId::CustomId):
    parseCustomSection(sectionSize, sectionContent, sectionPos);
    return Section(SectionId::CustomId, sectionSize, sectionContent, sectionPos);
  case (SectionId::TypeId):
    return parseTypeSection(sectionSize, sectionContent, sectionPos);
  case (SectionId::ImportId):
    return parseImportSection(sectionSize, sectionContent, sectionPos);
  case (SectionId::FunctionId):
    return parseFunctionSection(sectionSize, sectionContent, sectionPos);
  case (SectionId::TableId):
    return parseTableSection(sectionSize, sectionContent, sectionPos);
  case (SectionId::MemoryId):
    return parseMemorySection(sectionSize, sectionContent, sectionPos);
  case (SectionId::GlobalId):
    return parseGlobalSection(sectionSize, sectionContent, sectionPos);
  case (SectionId::ExportId):
    parseExportSection(sectionSize, sectionContent, sectionPos);
    return Section(SectionId::ExportId, sectionSize, sectionContent, sectionPos);
  case (SectionId::StartId):
    parseStartSection(sectionSize, sectionContent, sectionPos);
    return Section(SectionId::StartId, sectionSize, sectionContent, sectionPos);
  case (SectionId::ElementId):
    parseElementSection(sectionSize, sectionContent, sectionPos);
    return Section(SectionId::ElementId, sectionSize, sectionContent, sectionPos);
  case (SectionId::CodeId):
    parseCodeSection(sectionSize, sectionContent, sectionPos);
    return Section(SectionId::CodeId, sectionSize, sectionContent, sectionPos);
  case (SectionId::DataId):
    parseDataSection(sectionSize, sectionContent, sectionPos);
    return Section(SectionId::DataId, sectionSize, sectionContent, sectionPos);
  default:
    // TODO pretty error message
    BOOST_LOG_TRIVIAL(error) << "[module_parser] ErrorId at section " << hex << (unsigned int)sectionId << " with size "
                             << hex << sectionSize;
    Section section = Section(SectionId::ErrorId, sectionSize, sectionContent, 0);
    auto error = generateError(fatal, wrongSectionId, 0);
    section.addError(error);
    return section;
  }
}

int parseCustomSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  return 0; // TODO
}

TypeSection parseTypeSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto typesInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  TypeSection typeSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < typesInVector; i++) {
    Functype functype = parseFunctype(&sectionContent[pointer]);
    typeSection.addFunctype(functype);
    pointer += functype.getNBytes();
    if (functype.hasError()) {
      switch (functype.getError()->errorType) {
      case unrecognizedHeaderAtFunctype:
        cout << "ERROR parseTypeSection at header" << endl;
        break;
      case unrecognizedRT1Functype:
        cout << "ERROR parseTypeSection at RT1" << endl;
        break;
      case unrecognizedRT2Functype:
        cout << "ERROR parseTypeSection at RT2" << endl;
        break;
      default:
        cout << "ERROR parseTypeSection due to unknown reason" << endl;
        break;
      }
      return typeSection;
    }
  }
  typeSection.displaySectionContentInfo();
  return typeSection;
}

ImportSection parseImportSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto importsInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  ImportSection importSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < importsInVector; i++) {
    Import import = parseImport(&sectionContent[pointer]);
    importSection.addImport(import);
    pointer += import.getNBytes();
    if (import.hasError()) {
      switch (import.getError()->errorType) {
      case unrecognizedModAtImport:
        cout << "ERROR parseImportSection at mod" << endl;
        break;
      case unrecognizedNameAtImport:
        cout << "ERROR parseImportSection at name" << endl;
        break;
      case unrecognizedTabletypeAtImportDesc:
        cout << "ERROR parseImportSection at tabletype" << endl;
        break;
      case unrecognizedMemtypeAtImportDesc:
        cout << "ERROR parseImportSection at memtype" << endl;
        break;
      case unrecognizedGlobaltypeAtImportDesc:
        cout << "ERROR parseImportSection at globaltype" << endl;
        break;
      case unrecognizedHeaderAtImportDesc:
        cout << "ERROR parseImportSection at header byte" << endl;
        break;
      default:
        cout << "Unknown Error" << endl;
      }
      return importSection;
    }
  }
  importSection.displaySectionContentInfo();
  return importSection;
}

FuncSection parseFunctionSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto typeidxInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);

  FuncSection funcSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < typeidxInVector; i++) {
    uint32_t typeidx = transformLeb128ToUnsignedInt32(&sectionContent[pointer]);
    pointer += sizeOfLeb128(&sectionContent[pointer]);
    funcSection.addTypeidx(typeidx);
  }
  funcSection.displaySectionContentInfo();
  return funcSection;
}

TableSection parseTableSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto tablesInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);

  TableSection tableSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < tablesInVector; i++) {
    Tabletype tabletype = parseTableType(&sectionContent[pointer]);
    if (tabletype.limit.type == limit_min) {
      pointer += REFTYPE_SIZE + tabletype.limit.getNBytes();
    } else if (tabletype.limit.type == limit_min_max) {
      pointer += REFTYPE_SIZE + tabletype.limit.getNBytes();
    } else {
      // TODO error case
      cout << "ErrorId at parsing tabletype" << endl;
    }
    tableSection.addTabletype(tabletype);
  }
  tableSection.displaySectionContentInfo();
  return tableSection;
}

MemorySection parseMemorySection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto memsInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);

  MemorySection memorySection(sizeOfSection, sectionContent, sectionPos);

  for (uint32_t i = 0; i < memsInVector; i++) {
    Memtype memtype = parseMemType(&sectionContent[pointer]);
    if (memtype.limit.type == limit_min) {
      pointer += BYTES_LIMIT_MIN;
    } else if (memtype.limit.type == limit_min_max) {
      pointer += BYTES_LIMIT_MIN_MAX;
    } else {
      // TODO error case
    }
    memorySection.addMemtype(memtype);
  }
  memorySection.displaySectionContentInfo(); // TODO move to another place in the future
  return memorySection;
}

GlobalSection parseGlobalSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto globalsInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);

  GlobalSection globalSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < globalsInVector; i++) {
    auto global = parseGlobal(&sectionContent[pointer]);
    pointer += global.getNBytes();
    globalSection.addGlobal(global);
  }

  globalSection.displaySectionContentInfo(); // TODO move to another place in the future

  return globalSection; // TODO
}

int parseExportSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  return 0; // TODO
}

int parseStartSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  return 0; // TODO
}

int parseElementSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  return 0; // TODO
}

int parseCodeSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  return 0; // TODO
}

int parseDataSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  return 0; // TODO
}
} // namespace antiwasm
