#define BOOST_TEST_DYN_LINK

#include "memsec.cpp" //TODO remove if possible
#include "tablesec.cpp"
#include "typesec.cpp"
#include "reftype.cpp"
#include "section_parser.cpp"
#include "contentBlock.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(module_parser_test)

BOOST_AUTO_TEST_CASE(parseNextSection_canParseACorrectSection) {
  SectionId sectionId = SectionId::Custom;
  int sizeOfSection = 1;
  auto *contentOfSection = static_cast<uint8_t *>(
      malloc(sizeof(uint8_t) * sizeOfSection)); // Does not matter

  auto result =
      antiwasm::parseNextSection(sectionId, sizeOfSection, contentOfSection, 0);

  BOOST_CHECK_EQUAL(sectionId, result.getSectionId());
  BOOST_CHECK_EQUAL(sizeOfSection, result.getSize());
  BOOST_CHECK_EQUAL(contentOfSection, result.getContent());
}

BOOST_AUTO_TEST_CASE(
    parseNextSection_createsABadSectionIfEncountersAnUnknownSection) {
  uint8_t nonExistingSectionId = 100;
  int sizeOfSection = 1;
  auto *contentOfSection =
      static_cast<uint8_t *>(malloc(sizeof(uint8_t) * sizeOfSection));

  auto result = antiwasm::parseNextSection(nonExistingSectionId, sizeOfSection,
                                           contentOfSection, 0);

  BOOST_CHECK_EQUAL(SectionId::Error, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseCustomSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Custom, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Custom, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseTypeSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *typeSectionContent =
      static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 1));
  typeSectionContent[0] = 0; // Número de types en la sección

  auto result = antiwasm::parseNextSection(SectionId::Type, sizeOfSection,
                                           typeSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::Type, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseImportSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Import, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Import, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseFunctionSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result = antiwasm::parseNextSection(SectionId::Function, sizeOfSection,
                                           nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Function, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseTableSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *tableSectionContent =
      static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 1));
  tableSectionContent[0] = 0; // Número de tabletypeVector en la sección

  auto result = antiwasm::parseNextSection(SectionId::Table, sizeOfSection,
                                           tableSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::Table, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseTableSection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *tableSectionContent =
      static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 11));
  tableSectionContent[0] = 3; // Número de tabletypeVector en la sección
  tableSectionContent[1] = Reftype::funref, tableSectionContent[2] = limit_min,
  tableSectionContent[3] = 0x12;
  tableSectionContent[4] = Reftype::externref,
  tableSectionContent[5] = limit_min_max, tableSectionContent[6] = 0x00,
  tableSectionContent[7] = 0x0F;
  tableSectionContent[8] = Reftype::funref, tableSectionContent[9] = limit_min,
  tableSectionContent[10] = 0xCA;

  auto result = antiwasm::parseNextSection(SectionId::Table, sizeOfSection,
                                           tableSectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::Table, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseMemorySection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *memorySectionContent =
      static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 1));
  memorySectionContent[0] = 0; // Número de memtypes en la sección

  auto result = antiwasm::parseNextSection(SectionId::Memory, sizeOfSection,
                                           memorySectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::Memory, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseMemorySection_realisticSectionReturnsOkey) {
  int sizeOfSection = 0;
  auto *memorySectionContent =
      static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 8));
  memorySectionContent[0] = 3; // Número de memtypes en la sección
  memorySectionContent[1] = limit_min, memorySectionContent[2] = 0x12;
  memorySectionContent[3] = limit_min_max, memorySectionContent[4] = 0x00,
  memorySectionContent[5] = 0x0F;
  memorySectionContent[6] = limit_min, memorySectionContent[7] = 0xCA;

  auto result = antiwasm::parseNextSection(SectionId::Memory, sizeOfSection,
                                           memorySectionContent, 0);

  BOOST_CHECK_EQUAL(SectionId::Memory, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseGlobalSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Global, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Global, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseExportSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Export, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Export, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseStartSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Start, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Start, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseElementSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Element, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Element, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseCodeSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Code, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Code, result.getSectionId());
}

BOOST_AUTO_TEST_CASE(parseDataSection_emptySectionReturnsOkey) {
  int sizeOfSection = 0;

  auto result =
      antiwasm::parseNextSection(SectionId::Data, sizeOfSection, nullptr, 0);

  BOOST_CHECK_EQUAL(SectionId::Data, result.getSectionId());
}

BOOST_AUTO_TEST_SUITE_END()
