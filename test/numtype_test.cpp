#define BOOST_TEST_DYN_LINK

#include "../types/numtype.cpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(numtype_test)

BOOST_AUTO_TEST_CASE(parseNumType_casei32) {
  uint8_t numtypeContent = 0x7F;

  auto returnNumtype = antiwasm::parseNumType(numtypeContent);

  BOOST_CHECK_EQUAL(Numtype::i32, returnNumtype);
}

BOOST_AUTO_TEST_CASE(parseNumType_casei64) {
  uint8_t numtypeContent = 0x7E;

  auto returnNumtype = antiwasm::parseNumType(numtypeContent);

  BOOST_CHECK_EQUAL(Numtype::i64, returnNumtype);
}

BOOST_AUTO_TEST_CASE(parseNumType_casef32) {
  uint8_t numtypeContent = 0x7D;

  auto returnNumtype = antiwasm::parseNumType(numtypeContent);

  BOOST_CHECK_EQUAL(Numtype::f32, returnNumtype);
}

BOOST_AUTO_TEST_CASE(parseNumType_casef64) {
  uint8_t numtypeContent = 0x7C;

  auto returnNumtype = antiwasm::parseNumType(numtypeContent);

  BOOST_CHECK_EQUAL(Numtype::f64, returnNumtype);
}

BOOST_AUTO_TEST_CASE(parseNumType_caseInvalid) {
  uint8_t numtypeContent = 0xCA;

  auto returnNumtype = antiwasm::parseNumType(numtypeContent);

  BOOST_CHECK_EQUAL(Numtype::invalid_numtype, returnNumtype);
}

BOOST_AUTO_TEST_SUITE_END() // numtype_test
