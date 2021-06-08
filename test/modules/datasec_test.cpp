#define BOOST_TEST_DYN_LINK

#include "datasec_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(datasec_test)

BOOST_AUTO_TEST_CASE(datasec_constructor) {
    int size = 8;
    auto *content = new uint8_t[size];
    int initialPos = 0;

    DataSection dataSection(size, content, initialPos);

    BOOST_CHECK_EQUAL(SectionId::DataId, dataSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(datasec_addDataIncreasesVecSize) {
    int size = 8;
    auto *content = new uint8_t[size];
    int initialPos = 0;
    DataSection dataSection(size, content, initialPos);
    Data data = generateData();

    dataSection.addData(data);

    BOOST_CHECK_EQUAL(1, dataSection.getDataVector().size());
}


BOOST_AUTO_TEST_CASE(datasec_displaySectionHeaderInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  DataSection dataSection(size, content, initialPos);

  dataSection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_CASE(datasec_displaySectionContentInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  DataSection dataSection(size, content, initialPos);

  dataSection.displaySectionContentInfo();
}

BOOST_AUTO_TEST_SUITE_END() // data_test
