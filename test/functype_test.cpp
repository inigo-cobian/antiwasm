#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/functype.cpp"

BOOST_AUTO_TEST_SUITE(functype_test)

    BOOST_AUTO_TEST_CASE(parseFunctype) {
        unsigned char *functypeContent = nullptr; //TODO

        auto returnFunctype = antiwasm::parseFunctype(functypeContent);

        //BOOST_CHECK_EQUAL(Functype, returnFunctype); TODO
    }

BOOST_AUTO_TEST_SUITE_END() //functype_test
