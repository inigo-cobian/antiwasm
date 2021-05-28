#define BOOST_TEST_DYN_LINK

#include "../modules/module.cpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(module_test)

BOOST_AUTO_TEST_CASE(Module_returnsItsSize) {
  int sizeOfModule = 100;
  Module module(sizeOfModule);

  auto returnValue = module.getSize();

  BOOST_CHECK_EQUAL(sizeOfModule, returnValue);
}

BOOST_AUTO_TEST_CASE(Module_returnsASectionWithTheRequestedId) {
  Module module(20);
  SectionId sectionId = SectionId::TypeId;
  Section section(sectionId, 10, nullptr, 0);
  module.addSection(section);

  auto returnValue = module.getSection(sectionId);

  BOOST_CHECK_EQUAL(sectionId, returnValue.getSectionId());
}

BOOST_AUTO_TEST_CASE(Module_returnsAnErrorSectionIfNotDefinedtCreated) {
  Module module(20);

  auto returnValue = module.getSection(SectionId::TypeId);

  BOOST_CHECK_EQUAL(SectionId::ErrorId, returnValue.getSectionId());
}

BOOST_AUTO_TEST_CASE(containsSection_returnsTrueIfSectionExists) {
  Module module(20);
  SectionId sectionId = SectionId::TypeId;
  Section section(sectionId, 10, nullptr, 0);
  module.addSection(section);

  auto returnValue = module.containsSection(sectionId);

  BOOST_CHECK_EQUAL(true, returnValue);
}

BOOST_AUTO_TEST_CASE(containsSection_returnsFalseIfSectionDoesNotExist) {
  Module module(20);

  auto returnValue = module.containsSection(SectionId::TypeId);

  BOOST_CHECK_EQUAL(false, returnValue);
}

BOOST_AUTO_TEST_CASE(errorsCanBeAdded) {
  Module module(20);
  auto mockError = generateError(ErrorSeverity::warning, ErrorTypes::unknown, 0);

  module.addError(mockError);

  BOOST_CHECK_EQUAL(true, module.hasError());
}

BOOST_AUTO_TEST_CASE(displayError) {
  Module module(20);

  module.displayError();
}

BOOST_AUTO_TEST_SUITE_END() // module_test
