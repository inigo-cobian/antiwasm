#define BOOST_TEST_DYN_LINK

#include "../src/wasm_utils.cpp"
#include <boost/test/unit_test.hpp>
#include <cstdint>

BOOST_AUTO_TEST_SUITE(wasm_utils_test)

BOOST_AUTO_TEST_CASE(bytesToHexChar_correctFormatting) {
  const int nIncomingBytes = 2;
  auto *incomingBytes = (uint8_t *)malloc(sizeof(uint8_t) * nIncomingBytes);
  incomingBytes[0] = 0x02;
  incomingBytes[1] = 0xC8;

  auto *outgoingHexChars = bytesToHexChar(incomingBytes, 2);

  BOOST_CHECK_EQUAL(outgoingHexChars[0], '0');
  BOOST_CHECK_EQUAL(outgoingHexChars[1], '2');
  BOOST_CHECK_EQUAL(outgoingHexChars[2], 'C');
  BOOST_CHECK_EQUAL(outgoingHexChars[3], '8');
}

BOOST_AUTO_TEST_CASE(getHexChar_getsCharCorrectly) {
  uint8_t incomingByte = 0x2;

  char hexChar = getHexChar(incomingByte);

  BOOST_CHECK_EQUAL(hexChar, '2');
}

BOOST_AUTO_TEST_CASE(singleByteToTwoHexChar_getsTwoCharsCorrectly) {
  uint8_t incomingByte = 0xC2;
  auto *formattedChars = new char(2);

  singleByteToTwoHexChar(incomingByte, formattedChars);

  BOOST_CHECK_EQUAL(formattedChars[0], 'C');
  BOOST_CHECK_EQUAL(formattedChars[1], '2');
}

BOOST_AUTO_TEST_SUITE_END() // wasm_utils_tests
