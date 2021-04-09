#define BOOST_TEST_DYN_LINK

#include "../src/displayer.cpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(logger_test)

BOOST_AUTO_TEST_CASE(loggerPointerCanBeInstantiated) {

  std::unique_ptr<Displayer> logger = std::make_unique<Displayer>();

  BOOST_ASSERT(logger != nullptr);
}

BOOST_AUTO_TEST_CASE(loggerLevelIsInfoByDefault) {

  auto returnedLoggingLevel = Displayer::GetLoggingLevel();

  BOOST_CHECK_EQUAL(LoggingLevel::INFO, returnedLoggingLevel);
}

BOOST_AUTO_TEST_CASE(loggerLevelCanBeSet) {
  Displayer::SetLoggingLevel(LoggingLevel::VERBOSE);
  auto expectedLoggingLevel = LoggingLevel::VERBOSE;

  auto returnedLoggingLevel = Displayer::GetLoggingLevel();

  BOOST_CHECK_EQUAL(expectedLoggingLevel, returnedLoggingLevel);
}

BOOST_AUTO_TEST_CASE(loggerPrintsMessageOfSameLevel) {
  std::unique_ptr<Displayer> logger = std::make_unique<Displayer>();
  Displayer::SetLoggingLevel(LoggingLevel::INFO);

  logger->Log(LoggingLevel::INFO, "Don't be evil");

  // BOOST_CHECK_EQUAL(, "Don't be evil"); TODO check if it has been logged
}

BOOST_AUTO_TEST_CASE(loggerDoesNotPrintMessagesWithHigherLevel) {
  std::unique_ptr<Displayer> logger = std::make_unique<Displayer>();
  Displayer::SetLoggingLevel(LoggingLevel::INFO);

  logger->Log(LoggingLevel::PEDANTIC, "Don't be evil");

  // BOOST_CHECK_EQUAL(, "Don't be evil"); TODO check if it has been logged
}

BOOST_AUTO_TEST_CASE(loggerDoesNotPrintMessagesWithLowerLevel) {
  std::unique_ptr<Displayer> logger = std::make_unique<Displayer>();
  Displayer::SetLoggingLevel(LoggingLevel::VERBOSE);

  logger->Log(LoggingLevel::INFO, "Don't be evil");

  // BOOST_CHECK_EQUAL(, "Don't be evil"); TODO check if it has been logged
}

BOOST_AUTO_TEST_SUITE_END() // limits_test
