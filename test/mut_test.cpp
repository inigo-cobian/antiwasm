#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/mut.cpp"

BOOST_AUTO_TEST_SUITE(mut_test)

    BOOST_AUTO_TEST_CASE(parseMut_caseConst) {
        unsigned char mutContent = Mut::const_;

        auto returnMut = antiwasm::parseMut(mutContent);

        BOOST_CHECK_EQUAL(Mut::const_, returnMut);
    }

    BOOST_AUTO_TEST_CASE(parseMut_caseVar) {
        unsigned char mutContent = Mut::var_;

        auto returnMut = antiwasm::parseMut(mutContent);

        BOOST_CHECK_EQUAL(Mut::var_, returnMut);
    }

    BOOST_AUTO_TEST_CASE(parseMut_caseInvalid) {
        unsigned char mutContent = 0xCA;

        auto returnMut = antiwasm::parseMut(mutContent);

        BOOST_CHECK_EQUAL(Mut::invalid_mut, returnMut);
    }


BOOST_AUTO_TEST_SUITE_END() //mut_test
