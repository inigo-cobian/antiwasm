#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/logger.cpp"

BOOST_AUTO_TEST_SUITE( logger_test )

    BOOST_AUTO_TEST_CASE( loggerPointerCanBeInstantiated ) {

        std::unique_ptr<Logger> logger = std::make_unique<Logger>();

        BOOST_ASSERT(logger != nullptr);
    }

BOOST_AUTO_TEST_SUITE_END() //limits_test
