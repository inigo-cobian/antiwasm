#define BOOST_TEST_DYN_LINK

#include "codesec.cpp"
#include "contentBlock.cpp"
#include "end.cpp"
#include "expression.cpp"
#include "global.cpp"
#include "importsec.cpp"
#include "memsec.cpp"
#include "reftype.cpp"
#include "section_parser.cpp"
#include "tablesec.cpp"
#include "typesec.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(module_parser_test)

void initDisplayer() {
  Displayer::setSectionToDisplay("all");
}

BOOST_AUTO_TEST_CASE(parseNextSection_canParseACorrectSection) {
  initDisplayer();
  SectionId sectionId = SectionId::CustomId;
  int sizeOfSection = 1;
  auto *contentOfSection = new uint8_t[sizeOfSection]; // Does not matter

  auto result = antiwasm::parseNextSection(sectionId, sizeOfSection, contentOfSection, 0);

  BOOST_CHECK_EQUAL(sectionId, result.getSectionId());
  BOOST_CHECK_EQUAL(sizeOfSection, result.getSize());
  BOOST_CHECK_EQUAL(contentOfSection, result.getContent());
}

BOOST_AUTO_TEST_CASE(parseNextSection_createsABadSectionIfEncountersAnUnknownSection) {
  uint8_t nonExistingSectionId = 100;
  int sizeOfSection = 1;
  auto *contentOfSection = new uint8_t[sizeOfSection];

  auto result = antiwasm::parseNextSection(nonExistingSectionId, sizeOfSection, contentOfSection, 0);

  BOOST_CHECK_EQUAL(SectionId::UndefinedSectionId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseCustomSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::CustomId, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::CustomId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseTypeSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *typeSectionContent = new uint8_t[1];
  typeSectionContent[0] = 0; // Número de types en la sección

  auto result = antiwasm::parseNextSection(SectionId::TypeId, sizeOfSection, typeSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::TypeId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseTypeSection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *typeSectionContent = new uint8_t[1];
  typeSectionContent[0] = 1; // Número de types en la sección
  typeSectionContent[1] = FUNCTYPE_HEADER;
  typeSectionContent[2] = 2, typeSectionContent[3] = Numtype::i32, typeSectionContent[4] = Reftype::funref;
  typeSectionContent[5] = 1, typeSectionContent[6] = Numtype::f64;

  auto result = antiwasm::parseNextSection(SectionId::TypeId, sizeOfSection, typeSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::TypeId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseImportSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *importSectionContent = new uint8_t[1];
  importSectionContent[0] = 0; // Número de imports en la sección

  auto result = antiwasm::parseNextSection(SectionId::ImportId, sizeOfSection, importSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::ImportId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseImportSection_realisticSectionReturnsOkey) {
  int sizeOfSection = 1;
  auto *importSectionContent = new uint8_t[12];
  importSectionContent[0] = 1; // Número de types en la sección
  importSectionContent[1] = 4;
  importSectionContent[2] = 't', importSectionContent[3] = 'e', importSectionContent[4] = 's',
  importSectionContent[5] = 't';
  importSectionContent[6] = 3;
  importSectionContent[7] = 'F', importSectionContent[8] = 'o', importSectionContent[9] = 'o';
  importSectionContent[10] = ImportFunc;
  importSectionContent[11] = 1;

  auto result = antiwasm::parseNextSection(SectionId::ImportId, sizeOfSection, importSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::ImportId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseFunctionSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *functionSectionContent = new uint8_t[1];
  functionSectionContent[0] = 0; // Número de idxtypes en la sección

  auto result = antiwasm::parseNextSection(SectionId::FunctionId, sizeOfSection, functionSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::FunctionId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseFunctionSection_realisticSectionReturnsOkey) { // TODO
  int sizeOfSection = 0;
  auto *typeSectionContent = new uint8_t[1];
  typeSectionContent[0] = 3; // Número de idxtypes en la sección
  typeSectionContent[1] = 4, typeSectionContent[2] = 8, typeSectionContent[2] = 7;

  auto result = antiwasm::parseNextSection(SectionId::FunctionId, sizeOfSection, typeSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::FunctionId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseTableSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *tableSectionContent = new uint8_t[1];
  tableSectionContent[0] = 0; // Número de tabletypeVector en la sección

  auto result = antiwasm::parseNextSection(SectionId::TableId, sizeOfSection, tableSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::TableId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseTableSection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *tableSectionContent = new uint8_t[11];
  tableSectionContent[0] = 3; // Número de tabletypeVector en la sección
  tableSectionContent[1] = Reftype::funref, tableSectionContent[2] = limit_min, tableSectionContent[3] = 0x12;
  tableSectionContent[4] = Reftype::externref, tableSectionContent[5] = limit_min_max, tableSectionContent[6] = 0x00,
  tableSectionContent[7] = 0x0F;
  tableSectionContent[8] = Reftype::funref, tableSectionContent[9] = limit_min, tableSectionContent[10] = 0xCA;

  auto result = antiwasm::parseNextSection(SectionId::TableId, sizeOfSection, tableSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::TableId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseMemorySection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *memorySectionContent = new uint8_t[1];
  memorySectionContent[0] = 0; // Número de memtypes en la sección

  auto result = antiwasm::parseNextSection(SectionId::MemoryId, sizeOfSection, memorySectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::MemoryId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseMemorySection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *memorySectionContent = new uint8_t[8];
  memorySectionContent[0] = 3; // Número de memtypes en la sección
  memorySectionContent[1] = limit_min, memorySectionContent[2] = 0x12;
  memorySectionContent[3] = limit_min_max, memorySectionContent[4] = 0x00, memorySectionContent[5] = 0x0F;
  memorySectionContent[6] = limit_min, memorySectionContent[7] = 0xCA;

  auto result = antiwasm::parseNextSection(SectionId::MemoryId, sizeOfSection, memorySectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::MemoryId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseGlobalSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *globalSectionContent = new uint8_t[1];
  globalSectionContent[0] = 0; // Número de globals en la sección

  auto result = antiwasm::parseNextSection(SectionId::GlobalId, sizeOfSection, globalSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::GlobalId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseGlobalSection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *globalSectionContent = new uint8_t[5];
  globalSectionContent[0] = 1; // Número de globals en la sección
  globalSectionContent[1] = Reftype::funref, globalSectionContent[2] = Mut::var_;
  globalSectionContent[3] = InstructionSet::Nop, globalSectionContent[4] = InstructionSet::End;

  auto result = antiwasm::parseNextSection(SectionId::GlobalId, sizeOfSection, globalSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::GlobalId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseExportSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::ExportId, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::ExportId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseStartSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::StartId, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::StartId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseElementSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::ElementId, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::ElementId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseCodeSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *codeSectionContent = new uint8_t[1];
  codeSectionContent[0] = 0; // Número de codes en la sección

  auto result = antiwasm::parseNextSection(SectionId::CodeId, sizeOfSection, codeSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::CodeId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseCodeSection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *codeSectionContent = new uint8_t[8];
  codeSectionContent[0] = 1; // Número de codes en la sección
  codeSectionContent[1] = 0x05; // func size
  codeSectionContent[2] = 0x02; // localsVec size
  codeSectionContent[3] = Numtype::i64;
  codeSectionContent[4] = Numtype::f64;
  codeSectionContent[5] = i32_const, codeSectionContent[6] = 0x05, codeSectionContent[7] = End; // expr

  auto *codeContent = new uint8_t[7];

  auto result = antiwasm::parseNextSection(SectionId::CodeId, sizeOfSection, codeSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::CodeId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseDataSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *dataSectionContent = new uint8_t[1];
  dataSectionContent[0] = 0; // Número de datas en la sección

  auto result = antiwasm::parseNextSection(SectionId::DataId, sizeOfSection, dataSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::DataId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseDataSection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *dataSectionContent = new uint8_t[10];
  dataSectionContent[0] = 1; // Número de datas en la sección
  dataSectionContent[1] = modeActive_mem0;
  dataSectionContent[2] = InstructionSet::Nop, dataSectionContent[3] = End;
  dataSectionContent[4] = 0x05; // Number of bytes at the vector
  // Following bytes are not relevant

  auto result = antiwasm::parseNextSection(SectionId::DataId, sizeOfSection, dataSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::DataId, result.getSectionId());
}

BOOST_AUTO_TEST_SUITE_END()
