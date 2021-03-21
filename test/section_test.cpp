#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../modules/section.cpp"

BOOST_AUTO_TEST_SUITE(section_test)

    BOOST_AUTO_TEST_CASE(Section_canBeCreated)
    {
        int sectionSize = 20;
        int sectionIndex = 128;
        SectionId sectionId = SectionId::Type;
        auto *sectionContentMock = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 20));

        Section section(sectionId, sectionSize, sectionContentMock, sectionIndex);

    }

    BOOST_AUTO_TEST_CASE(getSectionId_returnsCorrectSectionId)
    {
        int sectionSize = 20;
        int sectionIndex = 128;
        SectionId sectionId = SectionId::Type;
        auto *sectionContentMock = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 20));
        Section section(sectionId, sectionSize, sectionContentMock, sectionIndex);

        auto result = section.getSectionId();

        BOOST_CHECK_EQUAL(sectionId, result);
    }

    BOOST_AUTO_TEST_CASE(getSize_returnsCorrectSize)
    {
        int sectionSize = 20;
        int sectionIndex = 128;
        SectionId sectionId = SectionId::Type;
        auto *sectionContentMock = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 20));
        Section section(sectionId, sectionSize, sectionContentMock, sectionIndex);

        auto result = section.getSize();

        BOOST_CHECK_EQUAL(sectionSize, result);
    }

    BOOST_AUTO_TEST_CASE(getContent_returnsAPointerWithTheSameInfo)
    {
        int sectionSize = 4;
        int sectionIndex = 128;
        SectionId sectionId = SectionId::Type;
        auto *sectionContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * sectionSize));
        sectionContent[0] = 0xCA;
        sectionContent[1] = 0xFE;
        sectionContent[0] = 0x19;
        sectionContent[1] = 0x97;
        Section section(sectionId, sectionSize, sectionContent, sectionIndex);

        auto *result = section.getContent();

        for (int i = 0; i < sectionSize; i++) {
            BOOST_CHECK_EQUAL(sectionContent[i], result[i]);
        }
    }

    BOOST_AUTO_TEST_CASE(getContent_returnsAPointerToTheSameDirection)
    {
        int sectionSize = 4;
        int sectionIndex = 128;
        SectionId sectionId = SectionId::Type;
        auto *sectionContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * sectionSize));
        sectionContent[0] = 0xCA;
        sectionContent[1] = 0xFE;
        sectionContent[0] = 0x19;
        sectionContent[1] = 0x97;
        Section section(sectionId, sectionSize, sectionContent, sectionIndex);

        auto *result = section.getContent();

        BOOST_CHECK_EQUAL(sectionContent, result);
    }

    BOOST_AUTO_TEST_CASE(getInitialPos_returnsTheValue)
    {
        int sectionSize = 4;
        int sectionIndex = 128;
        SectionId sectionId = SectionId::Type;
        auto *sectionContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * sectionSize));
        Section section(sectionId, sectionSize, sectionContent, sectionIndex);

        auto result = section.getInitialPos();

        BOOST_CHECK_EQUAL(sectionIndex, result);
    }


BOOST_AUTO_TEST_SUITE_END()
