#define BOOST_TEST_DYN_LINK

#include "typesec.hpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(typesec_test)

uint8_t *validFunctypeGenerator() {
  auto *functypeContent = new uint8_t[6];
  functypeContent[0] = FUNCTYPE_HEADER;
  functypeContent[1] = 2, functypeContent[2] = Numtype::i32, functypeContent[3] = Reftype::funref;
  functypeContent[4] = 1, functypeContent[5] = Numtype::f64;

  return functypeContent;
}

BOOST_AUTO_TEST_CASE(typesec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  TypeSection typeSection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::TypeId, typeSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(addType_addsTabletypeToTheVector) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  TypeSection typeSection(size, content, initialPos);
  Functype functypeMock = parseFunctype(validFunctypeGenerator());

  typeSection.addFunctype(functypeMock);

  BOOST_CHECK_EQUAL(1, typeSection.getFunctypeVector().size());
}

BOOST_AUTO_TEST_CASE(displaySectionHeaderInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  TypeSection typeSection(size, content, initialPos);

  typeSection.displaySectionHeaderInfo();

}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  TypeSection typeSection(size, content, initialPos);

  typeSection.displaySectionHeaderInfo();

}

BOOST_AUTO_TEST_SUITE_END() // typesec_test
