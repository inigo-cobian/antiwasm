#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/limits.cpp"

BOOST_AUTO_TEST_SUITE(limits_test)

    BOOST_AUTO_TEST_CASE(parseLimits_returnsTheTypeOfMinLimit) {
        auto *limitVec = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 2));
        limitVec[0] = limit_types::limit_min;
        limitVec[1] = 0x05;

        auto returnLimit = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnLimit.type, limit_types::limit_min);
    }

    BOOST_AUTO_TEST_CASE(parseLimits_returnsTheTypeOfMinMaxLimit) {
        auto *limitVec = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3));
        limitVec[0] = limit_types::limit_min_max;
        limitVec[1] = 0x05;
        limitVec[2] = 0x08;

        Limit returnLimit = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnLimit.type, limit_types::limit_min_max);
    }

    BOOST_AUTO_TEST_CASE(parseLimits_returnsAnErrorCodeWhenLimitsAreIncorrect) {
        auto *limitVec = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3));
        limitVec[0] = 0xFF/*incorrect limit type*/;
        limitVec[1] = 0x05;
        limitVec[2] = 0x08;

        Limit returnLimit = antiwasm::parseLimits(limitVec);

        BOOST_CHECK_EQUAL(returnLimit.error, true);
    }

BOOST_AUTO_TEST_SUITE_END() //limits_test
