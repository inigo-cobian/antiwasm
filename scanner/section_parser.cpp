#include "section_parser.hpp"

namespace antiwasm {

Section parseNextSection(uint8_t sectionId, int sectionSize, uint8_t *sectionContent, int sectionPos) {

  BOOST_LOG_TRIVIAL(debug) << "[module_parser] Info of the next section [" << hex << (unsigned int)sectionId
                           << "] with size " << hex << (unsigned int)sectionSize;
  switch (sectionId) {
  case (SectionId::Custom):
    parseCustomSection(sectionSize, sectionContent);
    return Section(SectionId::Custom, sectionSize, sectionContent, sectionPos);
  case (SectionId::Type):
    return parseTypeSection(sectionSize, sectionContent);
  case (SectionId::Import):
    parseImportSection(sectionSize, sectionContent);
    return Section(SectionId::Import, sectionSize, sectionContent, sectionPos);
  case (SectionId::Function):
    parseFunctionSection(sectionSize, sectionContent);
    return Section(SectionId::Function, sectionSize, sectionContent, sectionPos);
  case (SectionId::Table):
    return parseTableSection(sectionSize, sectionContent);
  case (SectionId::Memory):
    return parseMemorySection(sectionSize, sectionContent);
  case (SectionId::Global):
    parseGlobalSection(sectionSize, sectionContent);
    return Section(SectionId::Global, sectionSize, sectionContent, sectionPos);
  case (SectionId::Export):
    parseExportSection(sectionSize, sectionContent);
    return Section(SectionId::Export, sectionSize, sectionContent, sectionPos);
  case (SectionId::Start):
    parseStartSection(sectionSize, sectionContent);
    return Section(SectionId::Start, sectionSize, sectionContent, sectionPos);
  case (SectionId::Element):
    parseElementSection(sectionSize, sectionContent);
    return Section(SectionId::Element, sectionSize, sectionContent, sectionPos);
  case (SectionId::Code):
    parseCodeSection(sectionSize, sectionContent);
    return Section(SectionId::Code, sectionSize, sectionContent, sectionPos);
  case (SectionId::Data):
    parseDataSection(sectionSize, sectionContent);
    return Section(SectionId::Data, sectionSize, sectionContent, sectionPos);
  default:
    // TODO pretty error message
    BOOST_LOG_TRIVIAL(error) << "[module_parser] Error at section " << hex << (unsigned int)sectionId
                             << " with size " << hex << sectionSize;
    Section section = Section(SectionId::Error, sectionSize, sectionContent, 0);
    auto error = generateError(fatal, wrongSectionId, 0);
    section.addError(error);
    return section;
  }
}

int parseCustomSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

TypeSection parseTypeSection(int sizeOfSection, uint8_t *sectionContent) {
  auto typesInVector = transformLeb128ToUnsignedInt32(sectionContent);
  unsigned int pointer = sizeOfLeb128(sectionContent);
  TypeSection typeSection(sizeOfSection, sectionContent, 0); // TODO position
  for (u_int32_t i = 0; i < typesInVector; i++) {
    Functype functype = parseFunctype(&sectionContent[pointer]);
    typeSection.addFunctype(functype);
    pointer += functype.nBytes;
    if (functype.hasError()) {
      cout << "ERROR parseTypeSection" << endl;
      // TODO error case
      return typeSection;
    }
  }
  typeSection.displayTypesecContent();
  return typeSection;
}

int parseImportSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

int parseFunctionSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

TableSection parseTableSection(int sizeOfSection, uint8_t *sectionContent) {
  u_int32_t tablesInVector = sectionContent[0];
  unsigned int pointer = 1;
  TableSection tableSection(sizeOfSection, sectionContent, 0); // TODO position
  for (u_int32_t i = 0; i < tablesInVector; i++) {
    Tabletype tabletype = parseTableType(&sectionContent[pointer]);
    if (tabletype.limit.type == limit_min) {
      pointer += REFTYPE_SIZE + tabletype.limit.nBytes;
    } else if (tabletype.limit.type == limit_min_max) {
      pointer += REFTYPE_SIZE + tabletype.limit.nBytes;
    } else {
      // TODO error case
      cout << "Error at parsing tabletype" << endl;
    }
    tableSection.addTabletype(tabletype);
  }
  tableSection.displayTablesecContent();
  return tableSection;
}

MemorySection parseMemorySection(int sizeOfSection, uint8_t *sectionContent) {
  u_int32_t memsInVector = sectionContent[0];
  unsigned int pointer = 1;
  MemorySection memorySection(sizeOfSection, sectionContent, 0);

  for (u_int32_t i = 0; i < memsInVector; i++) {
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
  memorySection.displayMemsecContent(); // TODO move to another place in the future
  return memorySection;
}

int parseGlobalSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

int parseExportSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

int parseStartSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

int parseElementSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

int parseCodeSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}

int parseDataSection(int sizeOfSection, uint8_t *sectionContent) {
  return 0; // TODO
}
} // namespace antiwasm
