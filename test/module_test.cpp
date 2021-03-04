#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/module.cpp"

BOOST_AUTO_TEST_SUITE( module_test )

BOOST_AUTO_TEST_CASE(Module_returnsItsSize)
{
    int sizeOfModule = 100;
    Module module(sizeOfModule);

    auto returnValue = module.getSize();

    BOOST_CHECK_EQUAL(sizeOfModule, returnValue);
}

BOOST_AUTO_TEST_CASE(Module_returnsASectionWithTheRequestedId)
{
    Module module(20);
    antiwasm::SectionId sectionId = antiwasm::SectionId::Type;
    Section section(sectionId, 10, nullptr, 0);
    module.addSection(section);

    auto returnValue = module.getSection(sectionId);

    BOOST_CHECK_EQUAL(sectionId, returnValue.getSectionId());
}

BOOST_AUTO_TEST_CASE(Module_returnsAnErrorSectionIfNotDefinedtCreated)
{
    Module module(20);

    auto returnValue = module.getSection(antiwasm::SectionId::Type);

    BOOST_CHECK_EQUAL(antiwasm::SectionId::Error, returnValue.getSectionId());
}

BOOST_AUTO_TEST_CASE(containsSection_returnsTrueIfSectionExists)
{
    Module module(20);
    antiwasm::SectionId sectionId = antiwasm::SectionId::Type;
    Section section(sectionId, 10, nullptr, 0);
    module.addSection(section);

    auto returnValue = module.containsSection(sectionId);

    BOOST_CHECK_EQUAL(true, returnValue);

}

BOOST_AUTO_TEST_CASE(containsSection_returnsFalseIfSectionDoesNotExist)
{
    Module module(20);

    auto returnValue = module.containsSection(antiwasm::SectionId::Type);

    BOOST_CHECK_EQUAL(false, returnValue);
}

BOOST_AUTO_TEST_SUITE_END()
