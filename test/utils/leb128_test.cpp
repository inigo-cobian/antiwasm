#define BOOST_TEST_DYN_LINK

#include "leb128.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(leb128_test)

BOOST_AUTO_TEST_CASE(transformLeb128ToUnsignedInt32_oneByte) {
  auto *leb128Val = new uint8_t[1];
  leb128Val[0] = 0b0010'1011; // 43 in unsigned binary
  uint32_t expected = 43;

  auto returnVal = antiwasm::transformLeb128ToUnsignedInt32(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformLeb128ToUnsignedInt32_multipleBytes) {
  auto *leb128Val = new uint8_t[5];
  leb128Val[0] = 0xAA, leb128Val[1] = 0x86,
  leb128Val[2] = 0x00; // 810 in leb128
  uint32_t expected = 810;

  uint32_t returnVal = antiwasm::transformLeb128ToUnsignedInt32(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformLeb128ToUnsignedInt64_oneByte) {
  auto *leb128Val = new uint8_t[1];
  leb128Val[0] = 0b0010'1011; // 43 in unsigned binary
  uint32_t expected = 43;

  auto returnVal = antiwasm::transformLeb128ToUnsignedInt64(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformLeb128ToUnsignedInt64_multipleBytes) {
  auto *leb128Val = new uint8_t[5];
  leb128Val[0] = 0xAA, leb128Val[1] = 0x86,
  leb128Val[2] = 0x00; // 810 in leb128
  uint32_t expected = 810;

  uint32_t returnVal = antiwasm::transformLeb128ToUnsignedInt64(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformLeb128ToSignedInt32_oneByte) {
  auto *leb128Val = new uint8_t[1]; // -6
  leb128Val[0] = 0x7A;
  int32_t expected = -6;

  int32_t returnVal = antiwasm::transformLeb128ToSignedInt32(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformLeb128ToSignedInt32_multipleBytes) {
  auto *leb128Val = new uint8_t[3]; // -123456
  leb128Val[0] = 0xC0, leb128Val[1] = 0xBB,
  leb128Val[2] = 0x78;
  int32_t expected = -123456;

  int32_t returnVal = antiwasm::transformLeb128ToSignedInt32(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformLeb128ToSignedInt64_oneByte) {
  auto *leb128Val = new uint8_t[1]; // -6
  leb128Val[0] = 0x7A;
  int64_t expected = -6;

  int64_t returnVal = antiwasm::transformLeb128ToSignedInt64(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(transformLeb128ToSignedInt64_multipleBytes) {
  auto *leb128Val = new uint8_t[3]; // -123456
  leb128Val[0] = 0xC0, leb128Val[1] = 0xBB,
  leb128Val[2] = 0x78;
  int64_t expected = -123456;

  int64_t returnVal = antiwasm::transformLeb128ToSignedInt64(leb128Val);

  BOOST_CHECK_EQUAL(expected, returnVal);
}

BOOST_AUTO_TEST_CASE(sizeOfLeb128_threeBytes) {
  auto *leb128Val = new uint8_t[3];
  leb128Val[0] = 0b1000'0001, leb128Val[1] = 0b1110'1001, leb128Val[2] = 0b0010'1011;

  auto returnVal = antiwasm::sizeOfLeb128(leb128Val);

  BOOST_CHECK_EQUAL(3, returnVal);
}

BOOST_AUTO_TEST_SUITE_END() // leb128_test
