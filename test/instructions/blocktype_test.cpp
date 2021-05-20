#define BOOST_TEST_DYN_LINK

#include "blocktype.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(blocktype_test)

BOOST_AUTO_TEST_CASE(constructor_caseEmptyBlocktype) {
  auto * content = new uint8_t{0x40};

  auto contentBlock = parseBlocktype(content);

  BOOST_CHECK_EQUAL(contentBlock.type, emptyBlocktype);
}

BOOST_AUTO_TEST_CASE(constructor_caseValtypeBlocktype) {
  auto * content = new uint8_t{Numtype::i32}; // a.k.a numtype i32

  auto contentBlock = parseBlocktype(content);

  BOOST_CHECK_EQUAL(contentBlock.type, valtypeBlocktype);
  BOOST_CHECK_EQUAL(contentBlock.valtype.numtype, Numtype::i32);
}

BOOST_AUTO_TEST_CASE(constructor_caseTypeidxBlocktype) {
  auto * content = new uint8_t{0x01}; // a potential typeidx

  auto contentBlock = parseBlocktype(content);

  BOOST_CHECK_EQUAL(contentBlock.type, typeidxBlocktype);
}

BOOST_AUTO_TEST_SUITE_END() // blocktype_test
