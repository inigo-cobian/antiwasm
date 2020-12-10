#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/driver.cpp"

BOOST_AUTO_TEST_CASE(GetInstance_DoesCreateANotNullPtr)
{

    std::shared_ptr<Driver> driver = Driver::GetInstance();

    BOOST_CHECK(driver != nullptr);
}

BOOST_AUTO_TEST_CASE(A_Recently_Created_File_Is_Not_Parsing)
{
    std::shared_ptr<Driver> driver = Driver::GetInstance();

    bool isParsing = driver->IsCurrentlyParsing();

    BOOST_CHECK_EQUAL(isParsing, false);
}
