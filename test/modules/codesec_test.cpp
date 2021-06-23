#include "codesec_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(codesec_test)

BOOST_AUTO_TEST_CASE(codesec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  CodeSection codeSection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::CodeId, codeSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(codesec_addCodeIncreasesVecSize) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  CodeSection codeSection(size, content, initialPos);
  Code code = generateCode();

  codeSection.addCode(code);

  BOOST_CHECK_EQUAL(1, codeSection.getCodeVector().size());
}


BOOST_AUTO_TEST_CASE(codesec_displaySectionHeaderInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  CodeSection codeSection(size, content, initialPos);

  codeSection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_CASE(codesec_displaySectionContentInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  CodeSection codeSection(size, content, initialPos);

  codeSection.displaySectionContentInfo();
}

BOOST_AUTO_TEST_SUITE_END() // codesec_test
