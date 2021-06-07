#include "section_parser.hpp"

using namespace std;
namespace antiwasm {

Section parseNextSection(uint8_t sectionId, int sectionSize, uint8_t *sectionContent, int sectionPos) {

  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Info of the next section [" << (unsigned int)sectionId
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
    return parseDataSection(sectionSize, sectionContent, sectionPos);
  default:
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
  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Items at typesec [" << hex << (unsigned int)typesInVector << "]";

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
  if(Displayer::getSectionToDisplay() == SectionId::TypeId
      || Displayer::getSectionToDisplay() == SectionId::ErrorId) {
    typeSection.displaySectionContentInfo();
  }
  return typeSection;
}

ImportSection parseImportSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto importsInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Items at importsec [" << hex << (unsigned int)importsInVector << "]";

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
  if(Displayer::getSectionToDisplay() == SectionId::ImportId
     || Displayer::getSectionToDisplay() == SectionId::ErrorId) {
    importSection.displaySectionContentInfo();
  }
  return importSection;
}

FuncSection parseFunctionSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto typeidxInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Items at funcsec [" << hex << (unsigned int)typeidxInVector << "]";

  FuncSection funcSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < typeidxInVector; i++) {
    uint32_t typeidx = transformLeb128ToUnsignedInt32(&sectionContent[pointer]);
    pointer += sizeOfLeb128(&sectionContent[pointer]);
    funcSection.addTypeidx(typeidx);
  }
  if(Displayer::getSectionToDisplay() == SectionId::FunctionId
     || Displayer::getSectionToDisplay() == SectionId::ErrorId) {
    funcSection.displaySectionContentInfo();
  }
  return funcSection;
}

TableSection parseTableSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto tablesInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Items at tablesec [" << hex << (unsigned int)tablesInVector << "]";

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
  if(Displayer::getSectionToDisplay() == SectionId::TableId
     || Displayer::getSectionToDisplay() == SectionId::ErrorId) {
    tableSection.displaySectionContentInfo();
  }
  return tableSection;
}

MemorySection parseMemorySection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto memsInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Items at memsec [" << hex << (unsigned int)memsInVector << "]";

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
  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Items at globalsec [" << hex << (unsigned int)globalsInVector << "]";

  GlobalSection globalSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < globalsInVector; i++) {
    auto global = parseGlobal(&sectionContent[pointer]);
    pointer += global.getNBytes();
    globalSection.addGlobal(global); // TODO error
  }

  if(Displayer::getSectionToDisplay() == SectionId::GlobalId
     || Displayer::getSectionToDisplay() == SectionId::ErrorId) {
    globalSection.displaySectionContentInfo();
  }

  return globalSection;
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

DataSection parseDataSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos) {
  auto datasInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Items at datasec [" << hex << (unsigned int)datasInVector << "]";

  DataSection dataSection(sizeOfSection, sectionContent, sectionPos);
  for (uint32_t i = 0; i < datasInVector; i++) {
    BOOST_LOG_TRIVIAL(trace) << "[module_parser] Parsing data [" << i << "] at pos [" << pointer << "]";
    auto data = parseData(&sectionContent[pointer]);
    pointer += data.getNBytes();
    dataSection.addData(data);
    if(data.hasError()) {
      auto error = generateError(fatal, invalidDataAtDatasec, i);
      dataSection.addError(error);
      break;
    }
  }

  if(Displayer::getSectionToDisplay() == SectionId::DataId
     || Displayer::getSectionToDisplay() == SectionId::ErrorId) {
    dataSection.displaySectionContentInfo();
  }
  dataSection.displaySectionContentInfo();
  return dataSection;
}
} // namespace antiwasm
