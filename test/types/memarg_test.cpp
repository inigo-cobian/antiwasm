#define BOOST_TEST_DYN_LINK

#include "memarg.cpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(memarg_test)

BOOST_AUTO_TEST_CASE(parseMemarg_offset) {
    uint8_t memargContent[] = { 0x0A, 0x0B };

    auto result = antiwasm::MemArg(memargContent);

    BOOST_CHECK_EQUAL(result.offset, 0x0A);
}

BOOST_AUTO_TEST_CASE(parseMemarg_align) {
  uint8_t memargContent[] = { 0x0A, 0x0B };

    auto result = antiwasm::MemArg(memargContent);

    BOOST_CHECK_EQUAL(result.align, 0x0B);
}

BOOST_AUTO_TEST_SUITE_END() // memarg_test
