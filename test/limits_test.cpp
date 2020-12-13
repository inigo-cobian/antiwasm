#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/limits.cpp"

BOOST_AUTO_TEST_SUITE( limits_test )

BOOST_AUTO_TEST_CASE( parseLimitVec_returnsTrueWithCorrectMinLimit ) {
    constexpr unsigned char limitVec[] = {0x01, antiwasm::LIMIT_MIN, 0x05}; //aka [5-MAX]

    bool isSuccessful = antiwasm::parseLimitVec(const_cast<unsigned char *>(limitVec));

    BOOST_ASSERT(isSuccessful);
}

BOOST_AUTO_TEST_CASE( parseLimitVec_returnsTrueWithCorrectMinMaxLimit ) {
        constexpr unsigned char limitVec[] = {0x01, antiwasm::LIMIT_MIN_MAX, 0x05, 0x08}; //aka [5-8]

        bool isSuccessful = antiwasm::parseLimitVec(const_cast<unsigned char *>(limitVec));

        BOOST_ASSERT(isSuccessful);
}

BOOST_AUTO_TEST_CASE( parseLimitVec_returnsTrueWithMultipleCorrectLimits ) {

}

BOOST_AUTO_TEST_CASE( parseLimitVec_returnsFalseWithWronglyFormattedLimits ) {

}

BOOST_AUTO_TEST_CASE( getLimits_returnsTheTypeOfMinLimit ) {

}

BOOST_AUTO_TEST_CASE( getLimits_returnsTheTypeOfMinMaxLimit ) {

}

BOOST_AUTO_TEST_CASE( getLimits_returnsAnErrorCodeWhenLimitsAreIncorrect ) {

}

BOOST_AUTO_TEST_SUITE_END() //limits_test
