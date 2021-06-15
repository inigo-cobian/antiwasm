#define BOOST_TEST_DYN_LINK

#include "driver.cpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(driver_test)

const static char *FILE_PATH = "../../test/files/00-empty.wasm";

BOOST_AUTO_TEST_CASE(GetInstance_DoesCreateANotNullPtr) {

  shared_ptr<Driver> driver = Driver::GetInstance();

  BOOST_CHECK(driver != nullptr);
}

BOOST_AUTO_TEST_CASE(A_Recently_Created_File_Is_Not_Parsing) {
  shared_ptr<Driver> driver = Driver::GetInstance();

  bool isParsing = driver->IsCurrentlyParsing();

  BOOST_CHECK_EQUAL(isParsing, false);
}

BOOST_AUTO_TEST_CASE(An_Existing_File_Can_Be_Opened) {
  shared_ptr<Driver> driver = Driver::GetInstance();

  bool isOpen = driver->OpenFile(FILE_PATH);

  driver->CloseFile();
  BOOST_CHECK_EQUAL(isOpen, true);
}

BOOST_AUTO_TEST_CASE(A_non_existing_file_cannot_be_opened) {
  const char *filePath = "../../test/files/doesNotExists.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();

  bool isOpen = driver->OpenFile(filePath);

  driver->CloseFile();
  BOOST_CHECK_EQUAL(isOpen, false);
}

BOOST_AUTO_TEST_CASE(GetInstance_always_returns_the_same_instance) {

  shared_ptr<Driver> driver1 = Driver::GetInstance();
  shared_ptr<Driver> driver2 = Driver::GetInstance();

  BOOST_CHECK_EQUAL(driver1, driver2);
}

BOOST_AUTO_TEST_CASE(GetNextBytes_ReturnsThatNumberOfBytes) {
  const char *filePath = "../../test/files/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  const size_t nBytes = 4;
  constexpr uint8_t expectedBytes[] = {0x00, 0x61, 0x73, 0x6D}; // Magic number

  auto readBytes = driver->GetNextBytes(4);

  driver->CloseFile();
  BOOST_CHECK_EQUAL_COLLECTIONS(readBytes.get(), readBytes.get() + nBytes, expectedBytes, expectedBytes + nBytes);
}

BOOST_AUTO_TEST_CASE(GetNextSectionHeader_GetsMaxSizeOfSectionHeaderBytes) {
  const char *filePath = "../../test/files/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  constexpr uint8_t expectedBytes[] = {0x00, 0x61, 0x73, 0x6d, 0x01, 0x00}; // StartId of magic number
  size_t sizeOfSectionHeader = MAX_SIZE_OF_SECTION_HEADER;

  auto readBytes = driver->GetNextSectionHeader();

  driver->CloseFile();
  BOOST_CHECK_EQUAL_COLLECTIONS(readBytes.get(), readBytes.get() + sizeOfSectionHeader, expectedBytes,
                                expectedBytes + sizeOfSectionHeader);
}

BOOST_AUTO_TEST_CASE(GetNextBytes_WhenNotCurrentlyParsing) {
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->CloseFile();

  auto result = driver->GetNextBytes(0);

  BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(GetNextSectionHeader_WhenNotCurrentlyParsing) {
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->CloseFile();

  auto result = driver->GetNextSectionHeader();

  BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(GetFileSize_CaseCorrect) {
  const char *filePath = "../../test/files/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  size_t expectedSize = 8;

  auto result = driver->GetFileSize();

  BOOST_CHECK_EQUAL(expectedSize, result);
}

BOOST_AUTO_TEST_CASE(GetCurrentPos_StartsAtZero) {
  const char *filePath = "../../test/files/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  size_t expectedPos = 0;

  auto result = driver->GetCurrentPos();

  BOOST_CHECK_EQUAL(expectedPos, result);
}

BOOST_AUTO_TEST_CASE(GetCurrentPos_EvolvesAsItIsRead) {
  const char *filePath = "../../test/files/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  size_t bytesRead = 3;
  driver->GetNextBytes(3);

  auto result = driver->GetCurrentPos();

  BOOST_CHECK_EQUAL(bytesRead, result);
}

BOOST_AUTO_TEST_CASE(GetNextSectionHeader_AtFileEnd) {
  const char *filePath = "../../test/files/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  driver->GetNextBytes(9);

  auto result = driver->GetNextSectionHeader();

}

BOOST_AUTO_TEST_CASE(GetNextBytes_AtFileEnd) {
  const char *filePath = "../../test/files/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath);
  driver->GetNextBytes(9);

  auto result = driver->GetNextBytes(5);

}

BOOST_AUTO_TEST_SUITE_END() // driver_test
