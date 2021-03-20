#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/tabletype.cpp"

BOOST_AUTO_TEST_SUITE(tabletype_test)

    BOOST_AUTO_TEST_CASE(parseTableType) {
        unsigned char *tabletypeContent = nullptr; //TODO

        auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

        //BOOST_CHECK_EQUAL(Tabletype, returnTabletype); TODO
    }

BOOST_AUTO_TEST_SUITE_END() //tabletype_test
