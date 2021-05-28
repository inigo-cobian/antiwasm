#define BOOST_TEST_DYN_LINK

#include "../modules/header.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(header_test)

BOOST_AUTO_TEST_CASE(checkMagicNumber_returnsTrueWithCorrectMagicNum) {
  std::unique_ptr<uint8_t> magicNumber(new uint8_t[4]);
  magicNumber.get()[0] = 0x00, magicNumber.get()[1] = 0x61;
  magicNumber.get()[2] = 0x73, magicNumber.get()[3] = 0x6D;

  bool isCorrect = antiwasm::checkMagicNumber(std::move(magicNumber));

  BOOST_ASSERT(isCorrect);
}

BOOST_AUTO_TEST_CASE(checkMagicNumber_returnsFalseWithIncorrectMagicNum) {
  std::unique_ptr<uint8_t> notMagicNumber(new uint8_t[4]);
  notMagicNumber.get()[0] = 0x00, notMagicNumber.get()[1] = 0x00;
  notMagicNumber.get()[2] = 0x00, notMagicNumber.get()[3] = 0x00;

  bool isCorrect = antiwasm::checkMagicNumber(std::move(notMagicNumber));

  BOOST_CHECK_EQUAL(isCorrect, false);
}

BOOST_AUTO_TEST_CASE(checkVersion_correct) {
  std::unique_ptr<uint8_t> version1_0(new uint8_t[4]);
  version1_0.get()[0] = 0x01, version1_0.get()[1] = 0x00;
  version1_0.get()[2] = 0x00, version1_0.get()[3] = 0x00;

  bool isCorrect = antiwasm::checkVersion(std::move(version1_0));

  BOOST_ASSERT(isCorrect);
}

BOOST_AUTO_TEST_CASE(checkVersion_incorrect) {
  std::unique_ptr<uint8_t> incorrectVersion(new uint8_t[4]);
  incorrectVersion.get()[0] = 0x00, incorrectVersion.get()[1] = 0x00;
  incorrectVersion.get()[2] = 0x00, incorrectVersion.get()[3] = 0x00;

  bool isCorrect = antiwasm::checkVersion(std::move(incorrectVersion));

  BOOST_CHECK_EQUAL(isCorrect, false);
}

BOOST_AUTO_TEST_SUITE_END() // header_test
