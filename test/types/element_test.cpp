#include "element_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(element_test)

BOOST_AUTO_TEST_CASE(parseFunc_caseElem0) {
  auto *elementContent = new uint8_t[6];
  elementContent[0] = elem0;
  elementContent[1] = i32_const, elementContent[2] = 0x05, elementContent[3] = End; // expr
  elementContent[4] = 0x01, elementContent[5] = 0x00; // funcidxVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElem1) {
  auto *elementContent = new uint8_t[4];
  elementContent[0] = elem1;
  elementContent[1] = funcrefElemkind;
  elementContent[2] = 0x01, elementContent[3] = 0x00; // funcidxVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElem2) {
  auto *elementContent = new uint8_t[8];
  elementContent[0] = elem2;
  elementContent[1] = 0x00; // tableidx
  elementContent[2] = i32_const, elementContent[3] = 0x05, elementContent[4] = End; // expr
  elementContent[5] = funcrefElemkind;
  elementContent[6] = 0x01, elementContent[7] = 0x00; // funcidxVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElem3) {
  auto *elementContent = new uint8_t[4];
  elementContent[0] = elem3;
  elementContent[1] = funcrefElemkind;
  elementContent[2] = 0x01, elementContent[3] = 0x00; // funcidxVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElem4) {
  auto *elementContent = new uint8_t[8];
  elementContent[0] = elem4;
  elementContent[1] = i32_const, elementContent[2] = 0x05, elementContent[3] = End; // expr
  elementContent[4] = 0x01, elementContent[5] = i32_const, elementContent[6] = 0x05, elementContent[7] = End; // exprVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElem5) {
  auto *elementContent = new uint8_t[6];
  elementContent[0] = elem5;
  elementContent[1] = Reftype::funref;
  elementContent[2] = 0x01, elementContent[3] = i32_const, elementContent[4] = 0x05, elementContent[5] = End; // exprVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElem6) {
  auto *elementContent = new uint8_t[10];
  elementContent[0] = elem6;
  elementContent[1] = 0x00; // tableidx
  elementContent[2] = i32_const, elementContent[3] = 0x05, elementContent[4] = End; // expr
  elementContent[5] = Reftype::funref; // funcref
  elementContent[6] = 0x01, elementContent[7] = i32_const, elementContent[8] = 0x05, elementContent[9] = End; // exprVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElem7) {
  auto *elementContent = new uint8_t[6];
  elementContent[0] = elem7;
  elementContent[1] = Reftype::funref;
  elementContent[2] = 0x01, elementContent[3] = i32_const, elementContent[4] = 0x05, elementContent[5] = End; // exprVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(false, element.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElemHeaderInvalid) {
  auto *elementContent = new uint8_t[6];
  elementContent[0] = 0xAA; // invalid
  elementContent[1] = funcrefElemkind;
  elementContent[2] = 1, elementContent[3] = i32_const, elementContent[4] = 0x05, elementContent[5] = End; // exprVec

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(true, element.hasError());
  BOOST_CHECK_EQUAL(invalidHeaderAtElement, element.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElemKindInvalidAtElem2) {
  auto *elementContent = new uint8_t[6];
  elementContent[0] = elem2;
  elementContent[1] = 0x00; // tableidx
  elementContent[2] = i32_const, elementContent[3] = 0x05, elementContent[4] = End; // expr
  elementContent[5] = 0xAA;
  // irrelevant

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(true, element.hasError());
  BOOST_CHECK_EQUAL(invalidElemkindAtElement, element.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseFunc_caseElemKindInvalidAtElem3) {
  auto *elementContent = new uint8_t[4];
  elementContent[0] = elem3;
  elementContent[1] = 0xAA; // invalid
  // irrelevant

  auto element = parseElement(elementContent);
  auto str = element.getAsText(0);

  BOOST_CHECK_EQUAL(true, element.hasError());
  BOOST_CHECK_EQUAL(invalidElemkindAtElement, element.getError()->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // element_test
