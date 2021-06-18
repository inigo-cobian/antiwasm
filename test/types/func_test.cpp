#define BOOST_TEST_DYN_LINK

#include "func_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(func_test)

BOOST_AUTO_TEST_CASE(parseFunc_caseCorrect) {
  auto *funcContent = new uint8_t[8];
  funcContent[0] = 0x02; // localsVec size
  funcContent[1] = 0x01;
  funcContent[2] = Numtype::i32;
  funcContent[3] = 0x01;
  funcContent[4] = Numtype::f64;
  funcContent[5] = i32_const, funcContent[6] = 0x05, funcContent[7] = End; // expr

  auto func = parseFunc(funcContent);

  BOOST_CHECK_EQUAL(false, func.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseInvalidLocals) {
  auto *funcContent = new uint8_t[4];
  funcContent[0] = 0x02; // localsVec size
  funcContent[1] = 0x01; //
  funcContent[2] = 0xAA; // Invalid val
  funcContent[3] = InstructionSet::End; // expr

  auto func = parseFunc(funcContent);

  BOOST_CHECK_EQUAL(true, func.hasError());
  BOOST_CHECK_EQUAL(invalidLocalAtFunc, func.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseFunc_caseInvalidExpr) {
  auto *funcContent = new uint8_t[7];
  funcContent[0] = 0x02; // localsVec size
  funcContent[1] = 0x01;
  funcContent[2] = Numtype::i32;
  funcContent[4] = 0x01;
  funcContent[5] = Reftype::funref;
  funcContent[6] = InstructionSet::Else; // Invalid instr at this pos

  auto func = parseFunc(funcContent);

  BOOST_CHECK_EQUAL(true, func.hasError());
  BOOST_CHECK_EQUAL(invalidExprAtFunc, func.getError()->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // func_test
