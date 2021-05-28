#define BOOST_TEST_DYN_LINK

#include "nameParser.cpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(nameParser_test)

BOOST_AUTO_TEST_CASE(parseUTF8Name_SingleByteChar) {
  auto *bytes = new uint8_t[2];
  bytes[0] = 0x49;
  bytes[1] = 0x32;

  auto utf8 = parseUTF8Name(bytes, 2);

  BOOST_CHECK_EQUAL(utf8.name, "I2");
}

BOOST_AUTO_TEST_CASE(parseUTF8Name_MultipleByteChars) {
  auto *bytes = new uint8_t[10];
  bytes[0] = 0b00001111;                                                                      // valid single byte char
  bytes[1] = 0b11001111, bytes[2] = 0b10001111;                                               // valid two byte char
  bytes[3] = 0b11101111, bytes[4] = 0b10001111, bytes[5] = 0b10001111;                        // valid two byte char
  bytes[6] = 0b11110111, bytes[7] = 0b10001111, bytes[8] = 0b10001111, bytes[9] = 0b10001111; // valid two byte char

  auto utf8 = parseUTF8Name(bytes, 10);

  BOOST_CHECK_EQUAL(utf8.hasError(), false);
}

BOOST_AUTO_TEST_CASE(parseUTF8Name_errorLeadingByte) {
  auto *bytes = new uint8_t[3];
  bytes[0] = 0x49;
  bytes[1] = 0x83; // Incorrect leading byte
  bytes[2] = 'i';

  auto utf8 = parseUTF8Name(bytes, 3);

  BOOST_CHECK_EQUAL(unrecognizedUTF8LeadingByte, utf8.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseUTF8Name_errorContCharTwoBytes) {
  auto *bytes = new uint8_t[3];
  bytes[0] = 0x49;
  bytes[1] = 0xC3;
  bytes[2] = 0x01; // invalid continuation char

  auto utf8 = parseUTF8Name(bytes, 3);

  BOOST_CHECK_EQUAL(unrecognizedUTF8ContByte, utf8.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseUTF8Name_errorContCharThreeBytes) {
  auto *bytes = new uint8_t[3];
  bytes[0] = 0b11101111;
  bytes[1] = 0b10001111;
  bytes[2] = 0b00001111; // invalid continuation char

  auto utf8 = parseUTF8Name(bytes, 3);

  BOOST_CHECK_EQUAL(unrecognizedUTF8ContByte, utf8.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseUTF8Name_errorContCharFourBytes) {
  auto *bytes = new uint8_t[4];
  bytes[0] = 0b11110111;
  bytes[1] = 0b10001111;
  bytes[2] = 0b10001111;
  bytes[3] = 0b00001111; // invalid continuation char

  auto utf8 = parseUTF8Name(bytes, 4);

  BOOST_CHECK_EQUAL(unrecognizedUTF8ContByte, utf8.getError()->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // nameParser_test
