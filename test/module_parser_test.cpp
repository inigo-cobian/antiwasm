#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../src/module_parser.cpp"
#include "../modules/memsec.cpp" //TODO remove if possible
#include "../modules/tablesec.cpp"
#include "../types/tabletype.cpp"
#include "../types/reftype.cpp"

BOOST_AUTO_TEST_SUITE(module_parser_test)

    BOOST_AUTO_TEST_CASE(parseNextSection_canParseACorrectSection)
    {
        antiwasm::SectionId sectionId = antiwasm::SectionId::Custom;
        int sizeOfSection = 1;
        auto *contentOfSection = static_cast<unsigned char *>(malloc(
                sizeof(unsigned char) * sizeOfSection)); //Does not matter

        auto result = antiwasm::parseNextSection(sectionId, sizeOfSection, contentOfSection, 0);

        BOOST_CHECK_EQUAL(sectionId, result.getSectionId());
        BOOST_CHECK_EQUAL(sizeOfSection, result.getSize());
        BOOST_CHECK_EQUAL(contentOfSection, result.getContent());
    }

    BOOST_AUTO_TEST_CASE(parseNextSection_createsABadSectionIfEncountersAnUnknownSection)
    {
        unsigned char nonExistingSectionId = 100;
        int sizeOfSection = 1;
        auto *contentOfSection = static_cast<unsigned char *>(malloc(
                sizeof(unsigned char) * sizeOfSection)); //Does not matter

        auto result = antiwasm::parseNextSection(nonExistingSectionId, sizeOfSection, contentOfSection, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Error, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseCustomSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Custom, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Custom, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseTypeSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Type, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Type, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseImportSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Import, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Import, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseFunctionSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Function, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Function, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseTableSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;
        auto *tableSectionContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 1));
        tableSectionContent[0] = 0; //Número de tabletypes en la sección

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Table, sizeOfSection, tableSectionContent, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Table, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseMemorySection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;
        auto *memorySectionContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 1));
        memorySectionContent[0] = 0; //Número de memtypes en la sección

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Memory, sizeOfSection, memorySectionContent, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Memory, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseMemorySection_realisticSectionReturnsOkey)
    {
        int sizeOfSection = 0;
        auto *memorySectionContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 8));
        memorySectionContent[0] = 3; //Número de memtypes en la sección
        memorySectionContent[1] = limit_min; memorySectionContent[2] = 0x12;
        memorySectionContent[3] = limit_min_max; memorySectionContent[4] = 0x00; memorySectionContent[5] = 0x0F;
        memorySectionContent[6] = limit_min; memorySectionContent[7] = 0xCA;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Memory, sizeOfSection, memorySectionContent, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Memory, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseGlobalSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Global, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Global, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseExportSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Export, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Export, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseStartSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Start, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Start, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseElementSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Element, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Element, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseCodeSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Code, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Code, result.getSectionId());
    }

    BOOST_AUTO_TEST_CASE(parseDataSection_emptySectionReturnsOkey)
    {
        int sizeOfSection = 0;

        auto result = antiwasm::parseNextSection(antiwasm::SectionId::Data, sizeOfSection, nullptr, 0);

        BOOST_CHECK_EQUAL(antiwasm::SectionId::Data, result.getSectionId());
    }

BOOST_AUTO_TEST_SUITE_END()
