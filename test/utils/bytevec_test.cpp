#define BOOST_TEST_DYN_LINK

#include "bytevec.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(bytevec_test)

BOOST_AUTO_TEST_CASE(constructor_emptyVec) {
  auto *content = new uint8_t[1];
  content[0] = 0;

  ByteVec byteVec(content);

  BOOST_CHECK_EQUAL(0, byteVec.size);
}

BOOST_AUTO_TEST_CASE(constructor_regularVec) {
  auto *content = new uint8_t[12];
  content[0] = 12; // El resto de bytes no tienen relevancia

  ByteVec byteVec(content);

  BOOST_CHECK_EQUAL(12, byteVec.size);
}

BOOST_AUTO_TEST_CASE(getAsText_regularVec) {
  auto *content = new uint8_t[12];
  content[0] = 12; // El resto de bytes no tienen relevancia
  ByteVec byteVec(content);

  byteVec.getAsText();

}

BOOST_AUTO_TEST_SUITE_END() // bytevec_test
