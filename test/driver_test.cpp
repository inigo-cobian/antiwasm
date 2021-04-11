#define BOOST_TEST_DYN_LINK

#include "driver.cpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(driver_test)

const static char *FILE_PATH = "../../test/files/00-empty.wasm";

BOOST_AUTO_TEST_CASE(GetInstance_DoesCreateANotNullPtr) {

  std::shared_ptr<Driver> driver = Driver::GetInstance();

  BOOST_CHECK(driver != nullptr);
}

BOOST_AUTO_TEST_CASE(A_Recently_Created_File_Is_Not_Parsing) {
  std::shared_ptr<Driver> driver = Driver::GetInstance();

  bool isParsing = driver->IsCurrentlyParsing();

  BOOST_CHECK_EQUAL(isParsing, false);
}

BOOST_AUTO_TEST_CASE(An_Existing_File_Can_Be_Opened) {
  std::shared_ptr<Driver> driver = Driver::GetInstance();

  bool isOpen = driver->OpenFile(FILE_PATH);

  driver->CloseFile();
  BOOST_CHECK_EQUAL(isOpen, true);
}

BOOST_AUTO_TEST_CASE(A_non_existing_file_cannot_be_opened) {
  const char *filePath = "../../test/files/doesNotExists.wasm";
  std::shared_ptr<Driver> driver = Driver::GetInstance();

  bool isOpen = driver->OpenFile(filePath);

  driver->CloseFile();
  BOOST_CHECK_EQUAL(isOpen, false);
}

BOOST_AUTO_TEST_CASE(GetInstance_always_returns_the_same_instance) {

  std::shared_ptr<Driver> driver1 = Driver::GetInstance();
  std::shared_ptr<Driver> driver2 = Driver::GetInstance();

  BOOST_CHECK_EQUAL(driver1, driver2);
}

BOOST_AUTO_TEST_CASE(GetNextBytes_ReturnsThatNumberOfBytes) {
  const char *filePath = "../../test/files/00-empty.wasm";
  std::shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  const size_t nBytes = 4;
  constexpr uint8_t expectedBytes[] = {0x00, 0x61, 0x73, 0x6D}; // Magic number

  auto *readBytes = driver->GetNextBytes(4);

  driver->CloseFile();
  BOOST_CHECK_EQUAL_COLLECTIONS(readBytes, readBytes + nBytes, expectedBytes,
                                expectedBytes + nBytes);
}

BOOST_AUTO_TEST_CASE(GetNextSectionHeader_GetsMaxSizeOfSectionHeaderBytes) {
  const char *filePath = "../../test/files/00-empty.wasm";
  std::shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  constexpr uint8_t expectedBytes[] = {0x00, 0x61, 0x73, 0x6d,
                                       0x01, 0x00}; // Start of magic number
  size_t sizeOfSectionHeader = MAX_SIZE_OF_SECTION_HEADER;

  auto *readBytes = driver->GetNextSectionHeader();

  driver->CloseFile();
  BOOST_CHECK_EQUAL_COLLECTIONS(readBytes, readBytes + sizeOfSectionHeader,
                                expectedBytes,
                                expectedBytes + sizeOfSectionHeader);
}

BOOST_AUTO_TEST_SUITE_END() // driver_test
