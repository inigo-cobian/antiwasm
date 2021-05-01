#define BOOST_TEST_DYN_LINK

#include "importsec.hpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

uint8_t *validImportGenerator() {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;

  auto *importContent = new uint8_t[11];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = ImportDescType::ImportFunc;
  importContent[10] = typeidx;
  return importContent;
}

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
  Import importMock = parseImport(validImportGenerator());

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

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  ImportSection importSec(size, content, initialPos);

  importSec.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_SUITE_END() // import_test
