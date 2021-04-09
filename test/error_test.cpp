#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../utils/error.hpp"

BOOST_AUTO_TEST_SUITE(error_test)

    BOOST_AUTO_TEST_CASE(errorsCanBeCreatedAndAccessed) {

        antiwasm::Error error{nullptr, 0, antiwasm::error_types::unknown, antiwasm::error_severity::warning};

        BOOST_CHECK_EQUAL(antiwasm::error_types::unknown, error.errorType);
    }

BOOST_AUTO_TEST_SUITE_END() //error_test

