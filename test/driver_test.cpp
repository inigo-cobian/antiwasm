#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/driver.cpp"

BOOST_AUTO_TEST_SUITE( driver_test )

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

BOOST_AUTO_TEST_CASE(An_Existing_File_Can_Be_Opened)
{
    const char* filePath = "../../test/files/00-empty.wasm";
    std::shared_ptr<Driver> driver = Driver::GetInstance();

    bool isOpen = driver->OpenFile(filePath);

    BOOST_CHECK_EQUAL(isOpen, true);
}

BOOST_AUTO_TEST_CASE(A_non_existing_file_cannot_be_opened)
{
    const char* filePath = "../../test/files/doesNotExists.wasm";
    std::shared_ptr<Driver> driver = Driver::GetInstance();

    bool isOpen = driver->OpenFile(filePath);

    BOOST_CHECK_EQUAL(isOpen, false);
}


BOOST_AUTO_TEST_SUITE_END() //driver_test
