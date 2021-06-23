#include "globalsec_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(globalsec_test)

BOOST_AUTO_TEST_CASE(globalsec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  GlobalSection globalSection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::GlobalId, globalSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(globalsec_addGlobalIncreasesVecSize) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  GlobalSection globalSection(size, content, initialPos);
  Global global = generateGlobal();

  globalSection.addGlobal(global);

  BOOST_CHECK_EQUAL(1, globalSection.getGlobalVector().size());
}

BOOST_AUTO_TEST_CASE(globalsec_displaySectionHeaderInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  GlobalSection globalSection(size, content, initialPos);

  globalSection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_CASE(globalsec_displaySectionContentInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  GlobalSection globalSection(size, content, initialPos);
  Global global = generateGlobal();
  globalSection.addGlobal(global);

  globalSection.displaySectionContentInfo();
}

BOOST_AUTO_TEST_SUITE_END() // globalsec_test
