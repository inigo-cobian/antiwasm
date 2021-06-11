#define BOOST_TEST_DYN_LINK

#include "func_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(func_test)

BOOST_AUTO_TEST_CASE(parseFunc_caseCorrect) {
  auto *funcContent = new uint8_t[4];
  funcContent[0] = 0x02; // localsVec size
  funcContent[1] = Numtype::i32;
  funcContent[2] = Numtype::f64;
  funcContent[3] = InstructionSet::End; // expr

  auto func = parseFunc(funcContent);

  BOOST_CHECK_EQUAL(false, func.hasError());
}

BOOST_AUTO_TEST_CASE(parseFunc_caseInvalidLocals) {
  auto *funcContent = new uint8_t[4];
  funcContent[0] = 0x02; // localsVec size
  funcContent[1] = Numtype::i32;
  funcContent[2] = 0xAA; // Invalid val
  funcContent[3] = InstructionSet::End; // expr

  auto func = parseFunc(funcContent);

  BOOST_CHECK_EQUAL(true, func.hasError());
}

BOOST_AUTO_TEST_SUITE_END() // func_test
