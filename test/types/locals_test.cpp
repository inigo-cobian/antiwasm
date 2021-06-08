#define BOOST_TEST_DYN_LINK

#include "locals_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(locals_test)

BOOST_AUTO_TEST_CASE(parseLocals_caseCorrect) {
    auto *localsContent = new uint8_t[2];
    localsContent[0] = 0x02;
    localsContent[1] = Numtype::i32;

    auto locals = parseLocals(localsContent);

    BOOST_CHECK_EQUAL(false, locals.hasError());
}

BOOST_AUTO_TEST_CASE(parseLocals_caseInvalidValtype) {
    auto *localsContent = new uint8_t[2];
    localsContent[0] = 0x02;
    localsContent[1] = Numtype::invalid_numtype;

    auto locals = parseLocals(localsContent);

    BOOST_CHECK_EQUAL(true, locals.hasError());
}

BOOST_AUTO_TEST_SUITE_END() // locals_test
