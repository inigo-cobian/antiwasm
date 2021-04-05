#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/valtype.cpp"

BOOST_AUTO_TEST_SUITE(valttype_test)

    BOOST_AUTO_TEST_CASE(parseValtype_caseNumtype) {
        uint8_t valtypeContent = Numtype::f64;

        auto returnValtype = antiwasm::parseValtype(valtypeContent);

        BOOST_CHECK_EQUAL(Numtype::f64, returnValtype.numtype);
    }

    BOOST_AUTO_TEST_CASE(parseValtype_caseReftype) {
        uint8_t valtypeContent = Reftype::externref;

        auto returnValtype = antiwasm::parseValtype(valtypeContent);

        BOOST_CHECK_EQUAL(Reftype::externref, returnValtype.reftype);
    }


BOOST_AUTO_TEST_SUITE_END() //valttype_test
