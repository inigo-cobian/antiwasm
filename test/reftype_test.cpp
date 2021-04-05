#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/reftype.hpp"

BOOST_AUTO_TEST_SUITE(reftype_test)

    BOOST_AUTO_TEST_CASE(parseReftype_caseFunref) {
        uint8_t reftypeContent = 0x70;

        auto returnReftype = antiwasm::parseReftype(reftypeContent);

        BOOST_CHECK_EQUAL(Reftype::funref, returnReftype);
    }

    BOOST_AUTO_TEST_CASE(parseReftype_caseExternref) {
        uint8_t reftypeContent = 0x6F;

        auto returnReftype = antiwasm::parseReftype(reftypeContent);

        BOOST_CHECK_EQUAL(Reftype::externref, returnReftype);
    }

    BOOST_AUTO_TEST_CASE(parseReftype_casefunref) {
        uint8_t reftypeContent = 0xCA; //Invalid

        auto returnReftype = antiwasm::parseReftype(reftypeContent);

        BOOST_CHECK_EQUAL(Reftype::invalid_reftype, returnReftype);
    }


BOOST_AUTO_TEST_SUITE_END() //numtype_test
