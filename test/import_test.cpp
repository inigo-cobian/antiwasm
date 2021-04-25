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

  BOOST_CHECK_EQUAL(ErrorTypes::unrecognizedNameAtImport, import.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseImport_importDescIdError) {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;
  auto *importContent = new uint8_t[11];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = 0xFF; // Invalid ImportDescId
  importContent[10] = typeidx;

  auto import = parseImport(importContent);

  BOOST_CHECK_EQUAL(ErrorTypes::unrecognizedLimitHeaderAtTabletype, import.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseImport_importDescTabletypeError) {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto *importContent = new uint8_t[13];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = ImportDescType::ImportTable;
  importContent[10] = limit_types::limit_error; // error at tabletype.limit
  importContent[11] = 0x02;
  importContent[12] = Reftype::externref;

  auto import = parseImport(importContent);

  BOOST_CHECK_EQUAL(ErrorTypes::unrecognizedTabletypeAtImportDesc, import.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseImport_importDescMemtypeError) {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;
  auto *importContent = new uint8_t[12];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = ImportDescType::ImportMemtype;
  importContent[10] = limit_types::limit_error; // error at memtype.limit
  importContent[11] = 0x02;

  auto import = parseImport(importContent);

  BOOST_CHECK_EQUAL(ErrorTypes::unrecognizedMemtypeAtImportDesc, import.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseImport_importDescGlobaltypeError) {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;
  auto *importContent = new uint8_t[11];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = ImportDescType::ImportGlobaltype;
  importContent[10] = Mut::invalid_mut; // error at globaltype.mut
  importContent[11] = Reftype::externref;

  auto import = parseImport(importContent);

  BOOST_CHECK_EQUAL(ErrorTypes::unrecognizedGlobaltypeAtImportDesc, import.getError()->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // import_test
