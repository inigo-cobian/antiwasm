#define BOOST_TEST_DYN_LINK

#include "tablesec.hpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(tablesec_test)

uint8_t *validTabletypeGenerator() {
  auto limitType = limit_types::limit_min_max;

  auto *memtypeContent = new uint8_t[3];
  memtypeContent[0] = limitType;
  memtypeContent[1] = 0x12, memtypeContent[2] = 0x5F;
  return memtypeContent;
}

BOOST_AUTO_TEST_CASE(tablesec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  TableSection tableSection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::TableId, tableSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(addMemory_addsTabletypeToTheVector) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  TableSection tableSection(size, content, initialPos);
  Tabletype tabletypeMock = parseTableType(validTabletypeGenerator());

  tableSection.addTabletype(tabletypeMock);

  BOOST_CHECK_EQUAL(1, tableSection.getTabletypeVector().size());
}

BOOST_AUTO_TEST_CASE(displaySectionHeaderInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  TableSection tableSection(size, content, initialPos);

  tableSection.displaySectionHeaderInfo();

}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  TableSection tableSection(size, content, initialPos);

  tableSection.displaySectionHeaderInfo();

}

BOOST_AUTO_TEST_SUITE_END() // tablesec_test
