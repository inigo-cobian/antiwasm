#include "driver.cpp"
#include <boost/test/unit_test.hpp>
#include <string>

using namespace std;
using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(driver_test)

static const std::string FILE_PATH = std::string(TEST_DATA_DIR) + "/00-empty.wasm";

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

  bool isOpen = driver->OpenFile(FILE_PATH.c_str());

  driver->CloseFile();
  BOOST_CHECK_EQUAL(isOpen, true);
}

BOOST_AUTO_TEST_CASE(A_non_existing_file_cannot_be_opened) {
  std::string filePath = std::string(TEST_DATA_DIR) + "/doesNotExists.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();

  bool isOpen = driver->OpenFile(filePath.c_str());

  driver->CloseFile();
  BOOST_CHECK_EQUAL(isOpen, false);
}

BOOST_AUTO_TEST_CASE(GetInstance_always_returns_the_same_instance) {

  shared_ptr<Driver> driver1 = Driver::GetInstance();
  shared_ptr<Driver> driver2 = Driver::GetInstance();

  BOOST_CHECK_EQUAL(driver1, driver2);
}

BOOST_AUTO_TEST_CASE(GetNextBytes_ReturnsThatNumberOfBytes) {
  std::string filePath = std::string(TEST_DATA_DIR) + "/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath.c_str());
  const size_t nBytes = 4;
  constexpr uint8_t expectedBytes[] = {0x00, 0x61, 0x73, 0x6D}; // Magic number

  auto readBytes = driver->GetNextBytes(4);

  driver->CloseFile();
  BOOST_CHECK_EQUAL_COLLECTIONS(readBytes.get(), readBytes.get() + nBytes, expectedBytes, expectedBytes + nBytes);
}

BOOST_AUTO_TEST_CASE(GetNextSectionHeader_GetsMaxSizeOfSectionHeaderBytes) {
  std::string filePath = std::string(TEST_DATA_DIR) + "/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath.c_str());
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
  std::string filePath = std::string(TEST_DATA_DIR) + "/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath.c_str());
  size_t expectedSize = 8;

  auto result = driver->GetFileSize();

  BOOST_CHECK_EQUAL(expectedSize, result);
}

BOOST_AUTO_TEST_CASE(GetCurrentPos_StartsAtZero) {
  std::string filePath = std::string(TEST_DATA_DIR) + "/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath.c_str());
  size_t expectedPos = 0;

  auto result = driver->GetCurrentPos();

  BOOST_CHECK_EQUAL(expectedPos, result);
}

BOOST_AUTO_TEST_CASE(GetCurrentPos_EvolvesAsItIsRead) {
  std::string filePath = std::string(TEST_DATA_DIR) + "/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath.c_str());
  size_t bytesRead = 3;
  driver->GetNextBytes(3);

  auto result = driver->GetCurrentPos();

  BOOST_CHECK_EQUAL(bytesRead, result);
}

BOOST_AUTO_TEST_CASE(GetNextSectionHeader_AtFileEnd) {
  std::string filePath = std::string(TEST_DATA_DIR) + "/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath.c_str());
  driver->GetNextBytes(9);

  auto result = driver->GetNextSectionHeader();

}

BOOST_AUTO_TEST_CASE(GetNextBytes_AtFileEnd) {
  std::string filePath = std::string(TEST_DATA_DIR) + "/00-empty.wasm";
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->OpenFile(filePath.c_str());
  driver->GetNextBytes(9);

  auto result = driver->GetNextBytes(5);

}

// ============================================================
// Bug Condition Exploration Tests (Task 1)
// These tests encode the EXPECTED (correct) behavior.
// They are expected to FAIL on unfixed code, confirming the bug exists.
// Validates: Requirements 1.1, 1.2, 1.3, 1.4
// ============================================================

BOOST_AUTO_TEST_CASE(BugExploration_OpenFile_ReturnsTrue_ForFixturePath) {
  // Property 1: Bug Condition - CWD-Dependent Path Resolution
  // On unfixed code, FILE_PATH ("../../test/files/00-empty.wasm") does not resolve
  // from the build output CWD, so OpenFile returns false instead of true.
  shared_ptr<Driver> driver = Driver::GetInstance();

  bool isOpen = driver->OpenFile(FILE_PATH.c_str());

  BOOST_CHECK_EQUAL(isOpen, true);

  // After a successful open, IsCurrentlyParsing should be true
  BOOST_CHECK_EQUAL(driver->IsCurrentlyParsing(), true);

  // The real size of 00-empty.wasm is 8 bytes
  BOOST_CHECK_EQUAL(driver->GetFileSize(), 8);

  // The first 4 bytes should be the WASM magic number
  auto readBytes = driver->GetNextBytes(4);
  BOOST_REQUIRE(readBytes != nullptr);
  constexpr uint8_t wasmMagic[] = {0x00, 0x61, 0x73, 0x6D};
  BOOST_CHECK_EQUAL_COLLECTIONS(readBytes.get(), readBytes.get() + 4, wasmMagic, wasmMagic + 4);

  driver->CloseFile();
}

BOOST_AUTO_TEST_CASE(BugExploration_OpenGuard_FailedOpenLeavesNotParsing) {
  // Property 1: Bug Condition - Unguarded Open Failure
  // On unfixed code, OpenFile sets isParsing_ = true unconditionally,
  // even when the underlying ifstream::open fails.
  // This test calls OpenFile with a path that definitely does not exist,
  // then asserts IsCurrentlyParsing() == false.
  // On unfixed code, this assertion FAILS (isParsing_ is incorrectly true).
  shared_ptr<Driver> driver = Driver::GetInstance();

  bool isOpen = driver->OpenFile("/definitely/does/not/exist.wasm");
  BOOST_CHECK_EQUAL(isOpen, false);

  // After a FAILED open, IsCurrentlyParsing should be false
  // THIS WILL FAIL on unfixed code — confirming the open-guard bug
  BOOST_CHECK_EQUAL(driver->IsCurrentlyParsing(), false);

  driver->CloseFile();
}

// ============================================================
// Preservation Property Tests (Task 2)
// These tests document BASELINE behavior that must be preserved
// after the fix is applied. They should PASS on unfixed code.
// **Validates: Requirements 3.1, 3.2, 3.3, 3.4, 3.5**
// ============================================================

BOOST_AUTO_TEST_CASE(Preservation_OpenFile_NonexistentFile_ReturnsFalse) {
  // Property 2: Preservation - OpenFile with a genuinely nonexistent file returns false
  // This behavior must remain unchanged after the fix.
  // Validates: Requirement 3.1
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->CloseFile(); // Ensure clean state

  bool isOpen = driver->OpenFile("/this/path/absolutely/does/not/exist.wasm");

  BOOST_CHECK_EQUAL(isOpen, false);
  driver->CloseFile();
}

BOOST_AUTO_TEST_CASE(Preservation_GetNextBytes_ReturnsNullptr_WhenNotParsing) {
  // Property 2: Preservation - GetNextBytes returns nullptr when not currently parsing
  // This behavior must remain unchanged after the fix.
  // Validates: Requirement 3.3
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->CloseFile(); // Ensure not parsing

  auto result = driver->GetNextBytes(4);

  BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(Preservation_GetNextSectionHeader_ReturnsNullptr_WhenNotParsing) {
  // Property 2: Preservation - GetNextSectionHeader returns nullptr when not currently parsing
  // This behavior must remain unchanged after the fix.
  // Validates: Requirement 3.3
  shared_ptr<Driver> driver = Driver::GetInstance();
  driver->CloseFile(); // Ensure not parsing

  auto result = driver->GetNextSectionHeader();

  BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(Preservation_GetInstance_ReturnsNonNull) {
  // Property 2: Preservation - GetInstance always returns a non-null pointer
  // Singleton semantics must be unaffected by the fix.
  // Validates: Requirement 3.5
  shared_ptr<Driver> driver = Driver::GetInstance();

  BOOST_CHECK(driver != nullptr);
}

BOOST_AUTO_TEST_CASE(Preservation_GetInstance_AlwaysReturnsSamePointer) {
  // Property 2: Preservation - GetInstance always returns the same instance (singleton)
  // Singleton semantics must be unaffected by the fix.
  // Validates: Requirement 3.5
  shared_ptr<Driver> driver1 = Driver::GetInstance();
  shared_ptr<Driver> driver2 = Driver::GetInstance();

  BOOST_CHECK_EQUAL(driver1, driver2);
}

BOOST_AUTO_TEST_SUITE_END() // driver_test
