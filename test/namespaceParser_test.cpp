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
  auto *bytes = new uint8_t[4];
  bytes[0] = 0x49;
  bytes[1] = 0xC3; // ñ
  bytes[2] = 0xB1;
  bytes[3] = 'i';

  auto utf8 = parseUTF8Name(bytes, 4);

  BOOST_CHECK_EQUAL(utf8.name, "Iñi");
}

BOOST_AUTO_TEST_CASE(parseUTF8Name_errorLeadingChar) {
  auto *bytes = new uint8_t[3];
  bytes[0] = 0x49;
  bytes[1] = 0x83; // Incorrect leading byte
  bytes[2] = 'i';

  auto utf8 = parseUTF8Name(bytes, 3);

  BOOST_CHECK_EQUAL(unrecognizedUTF8LeadingByte, utf8.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(parseUTF8Name_errorContChar) {
  auto *bytes = new uint8_t[3];
  bytes[0] = 0x49;
  bytes[1] = 0xC3;
  bytes[2] = 0x01; // Incorrect cont byte

  auto utf8 = parseUTF8Name(bytes, 3);

  BOOST_CHECK_EQUAL(unrecognizedUTF8ContByte, utf8.getError()->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // nameParser_test
