#include "export_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(export_test)

BOOST_AUTO_TEST_CASE(parseExport_caseFuncidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::funcidxExport;
  exportContent[6] = 0x00;

  auto export_ = parseExport(exportContent);

  BOOST_CHECK_EQUAL(false, export_.hasError());
}

BOOST_AUTO_TEST_CASE(getAsText_caseFuncidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::funcidxExport;
  exportContent[6] = 0x00;
  auto export_ = parseExport(exportContent);

  auto str = export_.getAsText();

  BOOST_ASSERT(!str.empty());
}

BOOST_AUTO_TEST_CASE(parseExport_caseTableidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::tableidxExport;
  exportContent[6] = 0x00;

  auto export_ = parseExport(exportContent);

  BOOST_CHECK_EQUAL(false, export_.hasError());
}

BOOST_AUTO_TEST_CASE(getAsText_caseTableidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::tableidxExport;
  exportContent[6] = 0x00;
  auto export_ = parseExport(exportContent);

  auto str = export_.getAsText();

  BOOST_ASSERT(!str.empty());
}

BOOST_AUTO_TEST_CASE(parseExport_caseMemidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::memidxExport;
  exportContent[6] = 0x00;

  auto export_ = parseExport(exportContent);

  BOOST_CHECK_EQUAL(false, export_.hasError());
}

BOOST_AUTO_TEST_CASE(getAsText_caseMemidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::memidxExport;
  exportContent[6] = 0x00;
  auto export_ = parseExport(exportContent);

  auto str = export_.getAsText();

  BOOST_ASSERT(!str.empty());
}

BOOST_AUTO_TEST_CASE(parseExport_caseGlobalidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::globalidxExport;
  exportContent[6] = 0x00;

  auto export_ = parseExport(exportContent);

  BOOST_CHECK_EQUAL(false, export_.hasError());
}

BOOST_AUTO_TEST_CASE(getAsText_caseGlobalidx) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::globalidxExport;
  exportContent[6] = 0x00;
  auto export_ = parseExport(exportContent);

  auto str = export_.getAsText();

  BOOST_ASSERT(!str.empty());
}

BOOST_AUTO_TEST_CASE(parseExport_caseInvalidExportDesc) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::invalid_exportDesc;
  exportContent[6] = 0x00;

  auto export_ = parseExport(exportContent);

  BOOST_CHECK_EQUAL(true, export_.hasError());
  BOOST_CHECK_EQUAL(invalidExportDescAtExport, export_.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(getAsText_caseInvalidExportDesc) {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = ExportDesc::invalid_exportDesc;
  exportContent[6] = 0x00;
  auto export_ = parseExport(exportContent);

  auto str = export_.getAsText();

  BOOST_ASSERT(!str.empty());
}

BOOST_AUTO_TEST_SUITE_END() // export_test
