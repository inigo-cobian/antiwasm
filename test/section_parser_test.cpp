#define BOOST_TEST_DYN_LINK

#include "contentBlock.cpp"
#include "memsec.cpp" //TODO remove if possible
#include "reftype.cpp"
#include "section_parser.cpp"
#include "tablesec.cpp"
#include "typesec.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(module_parser_test)

BOOST_AUTO_TEST_CASE(parseNextSection_canParseACorrectSection) {
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

  BOOST_CHECK_EQUAL(SectionId::ErrorId, result.getSectionId());
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
  typeSectionContent[0] = 0; // Número de types en la sección
  typeSectionContent[1] = FUNCTYPE_HEADER;
  typeSectionContent[2] = 2, typeSectionContent[3] = Numtype::i32, typeSectionContent[4] = Reftype::funref;
  typeSectionContent[5] = 1, typeSectionContent[6] = Numtype::f64;

  auto result = antiwasm::parseNextSection(SectionId::TypeId, sizeOfSection, typeSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::TypeId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseImportSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::ImportId, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::ImportId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseFunctionSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::FunctionId, sizeOfSection, nullptr, 0);

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

  auto result = antiwasm::parseNextSection(SectionId::GlobalId, sizeOfSection, nullptr, 0);

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

  auto result = antiwasm::parseNextSection(SectionId::CodeId, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::CodeId, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseDataSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::DataId, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::DataId, result.getSectionId());
}

BOOST_AUTO_TEST_SUITE_END()
