#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/module.cpp"

BOOST_AUTO_TEST_SUITE( module_test )

BOOST_AUTO_TEST_CASE(Module_returnsItsSize)
{
    int sizeOfModule = 100;
    Module module(sizeOfModule);

    auto returnValue = module.getSize();

    BOOST_CHECK_EQUAL(sizeOfModule, returnValue);
}



BOOST_AUTO_TEST_SUITE_END()
