#include "elemsec_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(elemsec_test)

BOOST_AUTO_TEST_CASE(elemsec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  ElementSection elemSection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::ElementId, elemSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(elemsec_addElementIncreasesVecSize) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ElementSection elemSection(size, content, initialPos);
  Element element = generateElement();

  elemSection.addElement(element);

  BOOST_CHECK_EQUAL(1, elemSection.getElementVector().size());
}

BOOST_AUTO_TEST_CASE(elemsec_displaySectionHeaderInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ElementSection elemSection(size, content, initialPos);

  elemSection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_CASE(elemsec_displaySectionContentInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ElementSection elemSection(size, content, initialPos);
  Element element = generateElement();
  elemSection.addElement(element);

  elemSection.displaySectionContentInfo();
}

BOOST_AUTO_TEST_SUITE_END() // elemsec_test
