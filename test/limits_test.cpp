#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../src/limits.cpp"

BOOST_AUTO_TEST_SUITE(limits_test)

    BOOST_AUTO_TEST_CASE(parseLimits_returnsTheTypeOfMinLimit) {
        constexpr unsigned char limitVec[] = {antiwasm::LIMIT_MIN, 0x05}; //aka [5-MAX]

        auto returnValue = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnValue->type, limit_types::limit_min);
    }

    BOOST_AUTO_TEST_CASE(parseLimits_returnsTheTypeOfMinMaxLimit) {
        constexpr unsigned char limitVec[] = {antiwasm::LIMIT_MIN_MAX, 0x05, 0x08}; //aka [5-8]

        auto returnValue = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnValue->type, limit_types::limit_min_max);
    }

    BOOST_AUTO_TEST_CASE(parseLimits_returnsAnErrorCodeWhenLimitsAreIncorrect) {
        constexpr unsigned char limitVec[] = {0xFF/*incorrect limit type*/, 0x05, 0x08};

        auto returnValue = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnValue->error, true);
    }

BOOST_AUTO_TEST_SUITE_END() //limits_test
