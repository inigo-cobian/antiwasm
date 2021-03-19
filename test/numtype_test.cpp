#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/numtype.cpp"

BOOST_AUTO_TEST_SUITE(numtype_test)

    BOOST_AUTO_TEST_CASE(parseNumType_casei32) {
        unsigned char numtypeContent = 0x7F;

        auto returnNumtype = antiwasm::parseNumType(numtypeContent);

        BOOST_CHECK_EQUAL(Numtype::i32, returnNumtype);
    }

    BOOST_AUTO_TEST_CASE(parseNumType_casei64) {
        unsigned char numtypeContent = 0x7E;

        auto returnNumtype = antiwasm::parseNumType(numtypeContent);

        BOOST_CHECK_EQUAL(Numtype::i64, returnNumtype);
    }

    BOOST_AUTO_TEST_CASE(parseNumType_casef32) {
        unsigned char numtypeContent = 0x7D;

        auto returnNumtype = antiwasm::parseNumType(numtypeContent);

        BOOST_CHECK_EQUAL(Numtype::f32, returnNumtype);
    }

    BOOST_AUTO_TEST_CASE(parseNumType_casef64) {
        unsigned char numtypeContent = 0x7C;

        auto returnNumtype = antiwasm::parseNumType(numtypeContent);

        BOOST_CHECK_EQUAL(Numtype::f64, returnNumtype);
    }

    BOOST_AUTO_TEST_CASE(parseNumType_caseInvalid) {
        unsigned char numtypeContent = 0xCA;

        auto returnNumtype = antiwasm::parseNumType(numtypeContent);

        BOOST_CHECK_EQUAL(Numtype::invalid, returnNumtype);
    }


BOOST_AUTO_TEST_SUITE_END() //numtype_test
