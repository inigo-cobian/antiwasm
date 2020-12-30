#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/logger.cpp"

BOOST_AUTO_TEST_SUITE( logger_test )

    BOOST_AUTO_TEST_CASE( loggerPointerCanBeInstantiated ) {

        std::unique_ptr<Logger> logger = std::make_unique<Logger>();

        BOOST_ASSERT(logger != nullptr);
    }

    BOOST_AUTO_TEST_CASE( loggerLevelIsInfoByDefault ) {

        auto returnedLoggingLevel = Logger::GetLoggingLevel();

        BOOST_CHECK_EQUAL(LoggingLevel::INFO, returnedLoggingLevel);
    }

    BOOST_AUTO_TEST_CASE( loggerLevelCanBeSet ) {
        Logger::SetLoggingLevel(LoggingLevel::VERBOSE);
        auto expectedLoggingLevel = LoggingLevel::VERBOSE;

        auto returnedLoggingLevel = Logger::GetLoggingLevel();

        BOOST_CHECK_EQUAL(expectedLoggingLevel, returnedLoggingLevel);
    }


BOOST_AUTO_TEST_SUITE_END() //limits_test
