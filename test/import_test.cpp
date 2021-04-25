#define BOOST_TEST_DYN_LINK

#include "import.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(import_test)

BOOST_AUTO_TEST_CASE(parseImport_correct) {
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

  auto import = parseImport(importContent);

  BOOST_CHECK_EQUAL(false, import.hasError());
}

BOOST_AUTO_TEST_CASE(parseImport_moduleError) {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;
  auto *importContent = new uint8_t[11];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's';
  importContent[4] = 0b10001000; // Invalid byte
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = ImportDescType::ImportFunc;
  importContent[10] = typeidx;

  auto import = parseImport(importContent);

  BOOST_CHECK_EQUAL(ErrorTypes::unrecognizedModAtImport, import.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseImport_nameError) {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;
  auto *importContent = new uint8_t[11];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o';
  importContent[8] = 0b10001000; // Invalid byte
  importContent[9] = ImportDescType::ImportFunc;
  importContent[10] = typeidx;

  auto import = parseImport(importContent);

  BOOST_CHECK_EQUAL(ErrorTypes::unrecognizedModAtImport, import.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseImport_importDescTabletypeError) {
  // TODO
}

BOOST_AUTO_TEST_CASE(parseImport_importDescMemtypeError) {
  // TODO
}

BOOST_AUTO_TEST_CASE(parseImport_importDescGlobaltypeError) {
  // TODO
}

BOOST_AUTO_TEST_SUITE_END() // import_test
