#define BOOST_TEST_DYN_LINK

#include "displayer.hpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(displayer_test)

BOOST_AUTO_TEST_CASE(setSectionToDisplay_custom) {
  std::string sectionName = "custom";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_type) {
  std::string sectionName = "type";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_import) {
  std::string sectionName = "import";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_function) {
  std::string sectionName = "function";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_table) {
  std::string sectionName = "TABLE";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_memory) {
  std::string sectionName = "Memory";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_global) {
  std::string sectionName = "Global";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_export) {
  std::string sectionName = "Export";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_start) {
  std::string sectionName = "START";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_element) {
  std::string sectionName = "element";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_code) {
  std::string sectionName = "code";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_data) {
  std::string sectionName = "data";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_datacount) {
  std::string sectionName = "dataCount";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(result);
}

BOOST_AUTO_TEST_CASE(setSectionToDisplay_invalid) {
  std::string sectionName = "invalid";

  auto result = Displayer::setSectionToDisplay(sectionName);

  BOOST_ASSERT(!result);
}

BOOST_AUTO_TEST_CASE(getSectionToDisplay_caseCustom) {
  std::string sectionName = "Custom";
  Displayer::setSectionToDisplay(sectionName);

  auto result = Displayer::getSectionToDisplay();

  BOOST_CHECK_EQUAL(SectionId::CustomId, result);
}


BOOST_AUTO_TEST_SUITE_END() // displayer_test
