#define BOOST_TEST_DYN_LINK

#include "../utils/error_manager.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(error_test)

BOOST_AUTO_TEST_CASE(errorsCanBeCreatedAndAccessed) {

  auto error = generateError(ErrorSeverity::warning, ErrorTypes::unknown, 0);

  BOOST_CHECK_EQUAL(ErrorTypes::unknown, error->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // error_test