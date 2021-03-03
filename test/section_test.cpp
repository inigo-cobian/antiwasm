#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/section.cpp"

BOOST_AUTO_TEST_SUITE( section_test )

BOOST_AUTO_TEST_CASE(Section_canBeCreated)
{
    int sectionSize = 20;
    int sectionIndex = 128;
    antiwasm::SectionId sectionId = antiwasm::SectionId::Type;
    unsigned char * sectionContentMock = malloc(sizeof(unsigned char) * 20);

    Section section(sectionIndex, sectionId, sectionSize, sectionContentMock);

}

BOOST_AUTO_TEST_CASE(getSectionId_returnsCorrectSectionId)
{
    int sectionSize = 20;
    int sectionIndex = 128;
    antiwasm::SectionId sectionId = antiwasm::SectionId::Type;
    unsigned char * sectionContentMock = malloc(sizeof(unsigned char) * 20);
    Section section(sectionIndex, sectionId, sectionSize, sectionContentMock);

    auto result = section.getSectionId();

    BOOST_CHECK_EQUAL(sectionId, result);
}

BOOST_AUTO_TEST_CASE(getSize_returnsCorrectSize)
{
    int sectionSize = 20;
    int sectionIndex = 128;
    antiwasm::SectionId sectionId = antiwasm::SectionId::Type;
    unsigned char * sectionContentMock = malloc(sizeof(unsigned char) * 20);
    Section section(sectionIndex, sectionId, sectionSize, sectionContentMock);

    auto result = section.getSize();

    BOOST_CHECK_EQUAL(sectionSize, result);
}

BOOST_AUTO_TEST_SUITE_END()
