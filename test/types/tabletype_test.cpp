#define BOOST_TEST_DYN_LINK

#include "tabletype_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(tabletype_test)

BOOST_AUTO_TEST_CASE(parseTableType_caseCorrect) {
  auto *tabletypeContent = new uint8_t[3];
  tabletypeContent[0] = Reftype::funref;
  tabletypeContent[1] = limit_types::limit_min, tabletypeContent[2] = 0x05;

  auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

  BOOST_CHECK_EQUAL(false, returnTabletype.hasError());
}

BOOST_AUTO_TEST_CASE(parseTableType_caseErrorInReftype) {
  auto *tabletypeContent = new uint8_t[3];
  tabletypeContent[0] = 0xAA; // invalid
  tabletypeContent[1] = limit_types::limit_min,
  tabletypeContent[2] = 0x05; // should be ignored for this test

  auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

  BOOST_CHECK_EQUAL(true, returnTabletype.hasError());
}

BOOST_AUTO_TEST_CASE(parseTableType_caseErrorInLimit) {
  auto *tabletypeContent = new uint8_t[4];
  tabletypeContent[0] = Reftype::funref;
  tabletypeContent[1] = 0xAA,
  tabletypeContent[2] = 0x05; // limit type is invalid

  auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

  BOOST_CHECK_EQUAL(true, returnTabletype.hasError());
}

BOOST_AUTO_TEST_CASE(getAsText_caseLimitMin) {
  auto *tabletypeContent = new uint8_t[3];
  tabletypeContent[0] = Reftype::funref;
  tabletypeContent[1] = limit_types::limit_min, tabletypeContent[2] = 0x05;
  auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

  auto str = returnTabletype.getAsText();
}

BOOST_AUTO_TEST_CASE(getAsText_caseLimitMinMax) {
  auto *tabletypeContent = new uint8_t[4];
  tabletypeContent[0] = Reftype::funref;
  tabletypeContent[1] = limit_types::limit_min_max, tabletypeContent[2] = 0x05, tabletypeContent[3] = 0x08;
  auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

  auto str = returnTabletype.getAsText();
}

BOOST_AUTO_TEST_CASE(getAsText_caseLimitError) {
  auto *tabletypeContent = new uint8_t[4];
  tabletypeContent[0] = Reftype::funref;
  tabletypeContent[1] = 0xAA; // invalid
  tabletypeContent[2] = 0x05;
  auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

  auto str = returnTabletype.getAsText();
}

BOOST_AUTO_TEST_SUITE_END() // tabletype_test
