#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/numtype.cpp"

BOOST_AUTO_TEST_SUITE(numtype_test)

    BOOST_AUTO_TEST_CASE(parseNumType_casei32) {
        unsigned char numtypeContent = 0x7F;

        auto returnNumtype = antiwasm::parseNumType(numtypeContent);

        BOOST_CHECK_EQUAL(Numtype::i32, returnNumtype);
    }


BOOST_AUTO_TEST_SUITE_END() //numtype_test
