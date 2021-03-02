#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/module_parser.cpp"
#include "../src/types_parser.cpp"

BOOST_AUTO_TEST_SUITE( module_parser_test )

BOOST_AUTO_TEST_CASE(parseSections_canParseEverySection)
{/*
    std::shared_ptr<Driver> driver = Driver::GetInstance();
    driver->OpenFile("./files/basic-module.wasm");
    driver->GetNextBytes(8);
    auto *firstSectionHeader = driver->GetNextBytes(2);

    int result = antiwasm::parseSections(firstSectionHeader);

    BOOST_CHECK_EQUAL(0, result);*/
}

BOOST_AUTO_TEST_CASE(parseSections_failsIfEncountersAnUnknownSection)
{/*
    auto *firstHeader = (unsigned char*)malloc(sizeof(unsigned char) * 2);
    firstHeader[0] = 0xBB; // There's no section with ID = 0xBB

    int result = antiwasm::parseSections(firstHeader);

    BOOST_CHECK_EQUAL(1, result);*/
}

BOOST_AUTO_TEST_SUITE_END()
