#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/module_parser.cpp"
#include "../src/types_parser.cpp"

BOOST_AUTO_TEST_SUITE( module_parser_test )

static unsigned char mockSectionId = antiwasm::SectionId::Type; //TODO in a future manage custom
unsigned char* getMockHeaderInOrder() {
    auto *mockHeader = (unsigned char*)malloc(sizeof(unsigned char) * 2);
    mockHeader[0] = mockSectionId++; mockHeader[1] = 0x01;
    return mockHeader;
}

void setUpDriver() {
    std::shared_ptr<Driver> driver = Driver::GetInstance();
    driver->OpenFile("./files/basic-module.wasm"); //Irrelevant File for this test
}

BOOST_AUTO_TEST_CASE(parseSections_canParseEverySection)
{
    setUpDriver();
    auto *firstHeader = getMockHeaderInOrder();

    int result = antiwasm::parseSections(firstHeader);

    BOOST_CHECK_EQUAL(0, result);
}

BOOST_AUTO_TEST_CASE(parseSections_failsIfEncountersAnUnknownSection)
{
    setUpDriver();
    auto *firstHeader = (unsigned char*)malloc(sizeof(unsigned char) * 2);
    firstHeader[0] = 0xBB; // There's no section with ID = 0xBB

    int result = antiwasm::parseSections(firstHeader);

    BOOST_CHECK_EQUAL(1, result);
}

BOOST_AUTO_TEST_SUITE_END()
