#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/resulttype.cpp"

BOOST_AUTO_TEST_SUITE(resulttype_test)

    BOOST_AUTO_TEST_CASE(parseResulttype_correctResultType) {
        auto sizeOfValtypeVec = 3;
        unsigned char *resulttypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 4));
        resulttypeContent[0] = sizeOfValtypeVec;
        resulttypeContent[1] = Numtype::i32;
        resulttypeContent[2] = Reftype::externref;
        resulttypeContent[3] = Numtype::f64;

        auto returnResulttype = antiwasm::parseResulttype(resulttypeContent);

        BOOST_CHECK_EQUAL(sizeOfValtypeVec, returnResulttype.valtypeVector.size());
        BOOST_CHECK_EQUAL(Numtype::i32, returnResulttype.valtypeVector[0].numtype);
        BOOST_CHECK_EQUAL(Reftype::externref, returnResulttype.valtypeVector.at(1).reftype);
        BOOST_CHECK_EQUAL(Numtype::f64, returnResulttype.valtypeVector.at(2).numtype);
    }

    BOOST_AUTO_TEST_CASE(parseResulttype_errorResultType) {
        auto sizeOfValtypeVec = 3;
        unsigned char *resulttypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * 4));
        resulttypeContent[0] = sizeOfValtypeVec;
        resulttypeContent[1] = Numtype::i32;
        resulttypeContent[2] = 0xCA; //invalid
        resulttypeContent[3] = Numtype::f64;

        auto returnResulttype = antiwasm::parseResulttype(resulttypeContent);

        BOOST_CHECK_EQUAL(true, returnResulttype.error);
    }


BOOST_AUTO_TEST_SUITE_END() //resulttype_test
