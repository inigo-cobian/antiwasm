#include "exportsec_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(exportsec_test)

BOOST_AUTO_TEST_CASE(exportsec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  ExportSection exportSection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::ExportId, exportSection.getSectionId());
}

BOOST_AUTO_TEST_CASE(exportsec_addElementIncreasesVecSize) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ExportSection exportSection(size, content, initialPos);
  Export export_ = generateExport();

  exportSection.addExport(export_);

  BOOST_CHECK_EQUAL(1, exportSection.getExportVector().size());
}

BOOST_AUTO_TEST_CASE(exportsec_displaySectionHeaderInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ExportSection exportSection(size, content, initialPos);

  exportSection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_CASE(exportsec_displaySectionContentInfo) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ExportSection exportSection(size, content, initialPos);
  Export export_ = generateExport();
  exportSection.addExport(export_);

  exportSection.displaySectionContentInfo();
}

BOOST_AUTO_TEST_SUITE_END() // exportsec_test
