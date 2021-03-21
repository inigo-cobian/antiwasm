#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/functype.cpp"

BOOST_AUTO_TEST_SUITE(functype_test)

    BOOST_AUTO_TEST_CASE(parseFunctype_caseCorrectlyFormed) {
        unsigned char *functypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 6));
        functypeContent[0] = FUNCTYPE_HEADER;
        functypeContent[1] = 2, functypeContent[2] = Numtype::i32, functypeContent[3] = Reftype::funref;
        functypeContent[4] = 1, functypeContent[5] = Numtype::f64;

        auto returnFunctype = antiwasm::parseFunctype(functypeContent);

        BOOST_CHECK_EQUAL(false, returnFunctype.error);
    }

    BOOST_AUTO_TEST_CASE(parseFunctype_caseIncorrectHeader) {
        unsigned char *functypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 6));
        functypeContent[0] = 0x99; //Invalid header
        functypeContent[1] = 2, functypeContent[2] = Numtype::i32, functypeContent[3] = Reftype::funref; // Should be ignored
        functypeContent[4] = 1, functypeContent[5] = Numtype::f64; // Should be ignored

        auto returnFunctype = antiwasm::parseFunctype(functypeContent);

        BOOST_CHECK_EQUAL(true, returnFunctype.error);
    }

    BOOST_AUTO_TEST_CASE(parseFunctype_caseErrorAtParameters) {
        unsigned char *functypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 6));
        functypeContent[0] = FUNCTYPE_HEADER; //Invalid header
        functypeContent[1] = 2, functypeContent[2] = Numtype::i32, functypeContent[3] = 0xAA; // Invalid value
        functypeContent[4] = 1, functypeContent[5] = Numtype::f64; // Should be ignored

        auto returnFunctype = antiwasm::parseFunctype(functypeContent);

        BOOST_CHECK_EQUAL(true, returnFunctype.error);
    }

    BOOST_AUTO_TEST_CASE(parseFunctype_caseErrorAtParameters) {
        unsigned char *functypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 6));
        functypeContent[0] = FUNCTYPE_HEADER; //Invalid header
        functypeContent[1] = 2, functypeContent[2] = Numtype::i32, functypeContent[3] = Reftype::funref;
        functypeContent[4] = 1, functypeContent[5] = 0xAA; // Invalid value

        auto returnFunctype = antiwasm::parseFunctype(functypeContent);

        BOOST_CHECK_EQUAL(true, returnFunctype.error);
    }

BOOST_AUTO_TEST_SUITE_END() //functype_test
