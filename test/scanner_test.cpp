#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../includes//scanner.hpp"

BOOST_AUTO_TEST_SUITE( header_test )

const static  char* FILE_PATH = "../../test/files/00-empty.wasm";

BOOST_AUTO_TEST_CASE( parse_correctFile )
{
    int correctResult = 0;

    //int parseResult = antiwasm::parse(FILE_PATH);

    //BOOST_CHECK_EQUAL(parseResult, correctResult);
}


BOOST_AUTO_TEST_SUITE_END() //driver_test
