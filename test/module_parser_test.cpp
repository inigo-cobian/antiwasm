#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/module_parser.cpp"

BOOST_AUTO_TEST_SUITE( module_parser_test )

BOOST_AUTO_TEST_CASE(parseNextSection_canParseACorrectSection)
{
    antiwasm::SectionId sectionId = antiwasm::SectionId::Custom;
    int sizeOfSection = 1;
    auto* contentOfSection = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * sizeOfSection)); //Does not matter

    auto result = antiwasm::parseNextSection(sectionId, sizeOfSection, contentOfSection);

    BOOST_CHECK_EQUAL(0, result);
}

BOOST_AUTO_TEST_CASE(parseNextSection_failsIfEncountersAnUnknownSection)
{
    unsigned char nonExistingSectionId = 100;
    int sizeOfSection = 1;
    auto* contentOfSection = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * sizeOfSection)); //Does not matter

    auto result = antiwasm::parseNextSection(nonExistingSectionId, sizeOfSection, contentOfSection);

    BOOST_CHECK_EQUAL(1, result);
}

BOOST_AUTO_TEST_SUITE_END()
