#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/driver.cpp"

BOOST_AUTO_TEST_CASE(GetInstance_DoesCreateANotNullPtr)
{

    std::shared_ptr<Driver> driver = Driver::GetInstance();

    BOOST_CHECK(driver != nullptr); //TODO
}
