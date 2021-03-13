#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../src/limits.cpp"

BOOST_AUTO_TEST_SUITE(limits_test)

    BOOST_AUTO_TEST_CASE(parseLimitVec_returnsTrueWithCorrectMinLimit) {
        constexpr unsigned char limitVec[] = {0x01, antiwasm::LIMIT_MIN, 0x05}; //aka [5-MAX]

        bool isSuccessful = antiwasm::parseLimitVec(const_cast<unsigned char *>(limitVec));

        BOOST_ASSERT(isSuccessful);
    }

    BOOST_AUTO_TEST_CASE(parseLimitVec_returnsTrueWithCorrectMinMaxLimit) {
        constexpr unsigned char limitVec[] = {0x01, antiwasm::LIMIT_MIN_MAX, 0x05, 0x08}; //aka [5-8]

        bool isSuccessful = antiwasm::parseLimitVec(const_cast<unsigned char *>(limitVec));

        BOOST_ASSERT(isSuccessful);
    }

    BOOST_AUTO_TEST_CASE(parseLimitVec_returnsTrueWithMultipleCorrectLimits) {
        constexpr unsigned char limitVec[] = {0x03, antiwasm::LIMIT_MIN_MAX, 0x05, 0x08,
                                              antiwasm::LIMIT_MIN, 0x02,
                                              antiwasm::LIMIT_MIN_MAX, 0x00, 0x48};

        bool isSuccessful = antiwasm::parseLimitVec(const_cast<unsigned char *>(limitVec));

        BOOST_CHECK_EQUAL(isSuccessful, true);
    }

    BOOST_AUTO_TEST_CASE(parseLimitVec_returnsFalseWithWronglyFormattedLimits) {
        constexpr unsigned char limitVec[] = {0x01, 0xFF/*incorrect limit type*/, 0x05, 0x08};

        bool isSuccessful = antiwasm::parseLimitVec(const_cast<unsigned char *>(limitVec));

        BOOST_CHECK_EQUAL(isSuccessful, false);
    }

    BOOST_AUTO_TEST_CASE(parseLimits_returnsTheTypeOfMinLimit) {
        constexpr unsigned char limitVec[] = {antiwasm::LIMIT_MIN, 0x05}; //aka [5-MAX]

        auto returnValue = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnValue, antiwasm::CODE_LIMIT_MIN);
    }

    BOOST_AUTO_TEST_CASE(parseLimits_returnsTheTypeOfMinMaxLimit) {
        constexpr unsigned char limitVec[] = {antiwasm::LIMIT_MIN_MAX, 0x05, 0x08}; //aka [5-8]

        auto returnValue = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnValue, antiwasm::CODE_LIMIT_MIN_MAX);
    }

    BOOST_AUTO_TEST_CASE(parseLimits_returnsAnErrorCodeWhenLimitsAreIncorrect) {
        constexpr unsigned char limitVec[] = {0xFF/*incorrect limit type*/, 0x05, 0x08};

        auto returnValue = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnValue, -1);
    }

BOOST_AUTO_TEST_SUITE_END() //limits_test
