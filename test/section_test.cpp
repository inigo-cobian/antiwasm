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


BOOST_AUTO_TEST_SUITE_END()
