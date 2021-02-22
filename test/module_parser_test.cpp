#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/module_parser.cpp"
#include "../src/types_parser.cpp"

BOOST_AUTO_TEST_SUITE( module_parser_test )

//constexpr size_t SIZE_BASIC_MODULE = sizeof(unsigned char) * 12 * 3; //# of sections * size of sections
//unsigned char* BASIC_MODULE = static_cast<unsigned char *>(malloc(SIZE_BASIC_MODULE));
unsigned char BASIC_MODULE[] = {//antiwasm::SectionId::Custom, 0x01, 0x00, TODO
                antiwasm::SectionId::Type, 0x01, 0x00,
                antiwasm::SectionId::Import, 0x01, 0x00,
                antiwasm::SectionId::Function, 0x01, 0x00,
                antiwasm::SectionId::Table, 0x01, 0x00,
                antiwasm::SectionId::Memory, 0x01, 0x00,
                antiwasm::SectionId::Global, 0x01, 0x00,
                antiwasm::SectionId::Export, 0x01, 0x00,
                antiwasm::SectionId::Start, 0x01, 0x00,
                antiwasm::SectionId::Element, 0x01, 0x00,
                antiwasm::SectionId::Code, 0x01, 0x00,
                antiwasm::SectionId::Data, 0x01, 0x00
};

BOOST_AUTO_TEST_CASE(parseSections_canParseEverySection)
{

    int result = antiwasm::parseSections(&BASIC_MODULE[0]);

    BOOST_CHECK_EQUAL(0, result);
}

BOOST_AUTO_TEST_SUITE_END()
