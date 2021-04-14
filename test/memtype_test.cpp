#define BOOST_TEST_DYN_LINK

#include "../types/memtype.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(memtype_test)

BOOST_AUTO_TEST_CASE(parseMemType_doesNotCauseError) {
  auto *memtypeContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3));
  memtypeContent[0] = limit_types::limit_min_max;
  memtypeContent[1] = 0x05;
  memtypeContent[2] = 0x08;

  Memtype returnMemtype = antiwasm::parseMemType(memtypeContent);

  BOOST_CHECK_EQUAL(false, returnMemtype.hasError());
}

BOOST_AUTO_TEST_CASE(parseMemType_errorCase) {
  auto *memtypeContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3));
  memtypeContent[0] = 0xCF; // Does not exist
  memtypeContent[1] = 0x05;
  memtypeContent[1] = 0x08;

  Memtype returnMemtype = antiwasm::parseMemType(memtypeContent);

  BOOST_CHECK_EQUAL(true, returnMemtype.hasError());
}

BOOST_AUTO_TEST_CASE(displayMemcase_errorCase) {
  auto *memtypeContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3));
  memtypeContent[0] = 0xCF; // Does not exist
  memtypeContent[1] = 0x05;
  memtypeContent[1] = 0x08;
  Memtype returnMemtype = antiwasm::parseMemType(memtypeContent);

  displayMemtype(returnMemtype);
}

BOOST_AUTO_TEST_SUITE_END() // memtype_test
