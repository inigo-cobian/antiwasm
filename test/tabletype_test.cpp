#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/tabletype.cpp"

BOOST_AUTO_TEST_SUITE(tabletype_test)

    BOOST_AUTO_TEST_CASE(parseTableType_caseCorrect) {
        auto *tabletypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 4));
        tabletypeContent[0] = Reftype::funref;
        tabletypeContent[1] = limit_types::limit_min, tabletypeContent[2] = 0x05;

        auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

        BOOST_CHECK_EQUAL(false, returnTabletype.error);
    }

    BOOST_AUTO_TEST_CASE(parseTableType_caseErrorInReftype) {
        auto *tabletypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 4));
        tabletypeContent[0] = 0xAA; //invalid
        tabletypeContent[1] = limit_types::limit_min, tabletypeContent[2] = 0x05; // should be ignored for this test

        auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

        BOOST_CHECK_EQUAL(true, returnTabletype.error);
    }

    BOOST_AUTO_TEST_CASE(parseTableType_caseErrorInLimit) {
        auto *tabletypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 4));
        tabletypeContent[0] = Reftype::funref;
        tabletypeContent[1] = 0xAA, tabletypeContent[2] = 0x05; // limit type is invalid

        auto returnTabletype = antiwasm::parseTableType(tabletypeContent);

        BOOST_CHECK_EQUAL(true, returnTabletype.error);
    }

BOOST_AUTO_TEST_SUITE_END() //tabletype_test
