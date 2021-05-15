#define BOOST_TEST_DYN_LINK

#include "float_parser.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(float_parser_test)

BOOST_AUTO_TEST_CASE(transformf32ToFloat_test) {
  auto *f32Val = new uint8_t[4];
  f32Val[0] = 0x3f, f32Val[1] = 0x9d, f32Val[2] = 0xf3, f32Val[3] = 0xb6;
  float expected = 1.234;

  auto returnVal = transformf32ToFloat(f32Val);

  // Converted to int so precision errors can be avoided
  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformf64ToDouble_test) {
  auto *f64Val = new uint8_t[8];
  f64Val[0] = 0x40, f64Val[1] = 0x50, f64Val[2] = 0x5b, f64Val[3] = 0x85;
  f64Val[4] = 0x1e, f64Val[5] = 0xb8, f64Val[6] = 0x51, f64Val[7] = 0xec;

  double expected = 65.43;

  auto returnVal = transformf64ToDouble(f64Val);

  // Converted to int so precision errors can be avoided
  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_SUITE_END() // float_parser_test
