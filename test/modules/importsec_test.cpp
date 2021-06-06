#define BOOST_TEST_DYN_LINK

#include "importsec_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(importsec_test)

BOOST_AUTO_TEST_CASE(importsec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  ImportSection importSec(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::ImportId, importSec.getSectionId());
}

BOOST_AUTO_TEST_CASE(addImport_addsTheImportToTheVector) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ImportSection importSec(size, content, initialPos);
  Import importMock = parseImport(validImportFuncGenerator());

  importSec.addImport(importMock);

  BOOST_CHECK_EQUAL(1, importSec.getImportVector().size());
}

BOOST_AUTO_TEST_CASE(displaySectionHeaderInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ImportSection importSec(size, content, initialPos);

  importSec.displaySectionHeaderInfo();

}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_caseImportFunc) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ImportSection importSec(size, content, initialPos);
  Import importMock = parseImport(validImportFuncGenerator());
  importSec.addImport(importMock);

  importSec.displaySectionContentInfo();

}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_caseImportTable) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  Import importMock = parseImport(validImportTableGenerator());
  ImportSection importSec(size, content, initialPos);
  importSec.addImport(importMock);

  importSec.displaySectionContentInfo();

}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_caseImportMemtype) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  Import importMock = parseImport(validImportMemtypeGenerator());
  ImportSection importSec(size, content, initialPos);
  importSec.addImport(importMock);

  importSec.displaySectionContentInfo();

}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_caseImportGlobaltype) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  Import importMock = parseImport(validImportGlobalGenerator());
  ImportSection importSec(size, content, initialPos);
  importSec.addImport(importMock);

  importSec.displaySectionContentInfo();

}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_caseImportInvalid) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  Import importMock = parseImport(invalidImportGenerator());
  ImportSection importSec(size, content, initialPos);
  importSec.addImport(importMock);

  importSec.displaySectionContentInfo();

}

BOOST_AUTO_TEST_SUITE_END() // import_test
