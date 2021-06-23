#include "funcsec_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(funcsec_test)

BOOST_AUTO_TEST_CASE(funcsec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  FuncSection funcSection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::FunctionId, funcSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(funcsec_addTypeidxIncreasesVecSize) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  FuncSection funcSection(size, content, initialPos);

  funcSection.addTypeidx(0x00);

  BOOST_CHECK_EQUAL(1, funcSection.getTypeidxVector().size());
}

BOOST_AUTO_TEST_CASE(funcsec_displaySectionHeaderInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  FuncSection funcSection(size, content, initialPos);

  funcSection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_CASE(funcsec_displaySectionContentInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  FuncSection funcSection(size, content, initialPos);
  funcSection.addTypeidx(0x00);

  funcSection.displaySectionContentInfo();
}

BOOST_AUTO_TEST_SUITE_END() // funcsec_test
