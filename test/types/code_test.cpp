#include "code_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(code_test)

BOOST_AUTO_TEST_CASE(parseCode_caseCorrect) {
  auto *codeContent = new uint8_t[7];
  codeContent[0] = 0x06; // func size
  // first func
  codeContent[1] = 0x02; // localsVec size
  codeContent[2] = Numtype::i32;
  codeContent[3] = Numtype::f64;
  codeContent[4] = i32_const, codeContent[5] = 0x05, codeContent[6] = End; // expr

  auto code = parseCode(codeContent);

  BOOST_CHECK_EQUAL(false, code.hasError());
}

BOOST_AUTO_TEST_CASE(parseCode_caseInvalidFunc) {
  auto *codeContent = new uint8_t[7];
  codeContent[0] = 0x05; // func size
  // first func
  codeContent[1] = 0x02; // localsVec size
  codeContent[2] = 0xAA; // invalid local
  codeContent[3] = Numtype::f64;
  codeContent[4] = i32_const, codeContent[5] = 0x05, codeContent[6] = End; // expr

  auto code = parseCode(codeContent);

  BOOST_CHECK_EQUAL(true, code.hasError());
  BOOST_CHECK_EQUAL(invalidFuncAtCode, code.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseCode_caseSizeOfFuncDoesNotMatch) {
  auto *codeContent = new uint8_t[7];
  codeContent[0] = 0x01; // incorrect func size
  // first func
  codeContent[1] = 0x02; // localsVec size
  codeContent[2] = Numtype::i32;
  codeContent[3] = Numtype::f64;
  codeContent[4] = i32_const, codeContent[5] = 0x05, codeContent[6] = End; // expr

  auto code = parseCode(codeContent);

  BOOST_CHECK_EQUAL(true, code.hasError());
  BOOST_CHECK_EQUAL(notMatchingSizeOfFuncAtCode, code.getError()->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // code_test
