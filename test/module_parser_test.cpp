#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/module_parser.cpp"
#include "../src/types_parser.cpp"

BOOST_AUTO_TEST_SUITE( module_parser_test )

constexpr size_t SIZE_BASIC_MODULE = sizeof(unsigned char) * 12 * 3 + 1; //# of sections * size of sections

unsigned char* setupBasicModule() {
    auto* basicModule = static_cast<unsigned char *>(malloc(SIZE_BASIC_MODULE));
    basicModule[0] = antiwasm::SectionId::Type; basicModule[1] = 0x01; basicModule[2] = 0x00;
    basicModule[4] = antiwasm::SectionId::Import; basicModule[5] = 0x02; basicModule[6] = 0x00;
    basicModule[7] = antiwasm::SectionId::Function; basicModule[8] = 0x02; basicModule[9] = 0x00;
    basicModule[10] = antiwasm::SectionId::Table; basicModule[11] = 0x02; basicModule[12] = 0x00;
    basicModule[13] = antiwasm::SectionId::Memory; basicModule[14] = 0x02; basicModule[15] = 0x00;
    basicModule[16] = antiwasm::SectionId::Global; basicModule[17] = 0x02; basicModule[18] = 0x00;
    basicModule[19] = antiwasm::SectionId::Export; basicModule[20] = 0x02; basicModule[21] = 0x00;
    basicModule[22] = antiwasm::SectionId::Start; basicModule[22] = 0x02; basicModule[23] = 0x00;
    basicModule[24] = antiwasm::SectionId::Element; basicModule[25] = 0x02; basicModule[26] = 0x00;
    basicModule[27] = antiwasm::SectionId::Code; basicModule[28] = 0x02; basicModule[29] = 0x00;
    basicModule[30] = antiwasm::SectionId::Data; basicModule[31] = 0x02; basicModule[32] = 0x00;
    basicModule[33] = antiwasm::SectionId::Custom; basicModule[34] = 0x02; basicModule[35] = 0x00;
    return basicModule;
}

BOOST_AUTO_TEST_CASE(parseSections_canParseEverySection)
{
    auto basicModule = setupBasicModule();

    int result = antiwasm::parseSections(basicModule);

    BOOST_CHECK_EQUAL(0, result);
}

BOOST_AUTO_TEST_CASE(parseSections_failsIfEncountersAnUnknownSection)
{
    auto basicModule = setupBasicModule();
    basicModule[0] = 0xBB; //There is no section with ID 0xBB

    int result = antiwasm::parseSections(basicModule);

    BOOST_CHECK_EQUAL(1, result);
}

BOOST_AUTO_TEST_SUITE_END()
