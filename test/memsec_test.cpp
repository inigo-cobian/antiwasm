#define BOOST_TEST_DYN_LINK

#include "memsec.hpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(memsec_test)

uint8_t *validMemtypeGenerator() {
  auto limitType = limit_types::limit_min_max;

  auto *memtypeContent = new uint8_t[3];
  memtypeContent[0] = limitType;
  memtypeContent[1] = 0x12, memtypeContent[2] = 0x5F;
  return memtypeContent;
}

BOOST_AUTO_TEST_CASE(memsec_constructor) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;

  MemorySection memorySection(size, content, initialPos);

  BOOST_CHECK_EQUAL(SectionId::MemoryId, memorySection.getSectionId());
}

BOOST_AUTO_TEST_CASE(addMemory_addsMemoryToTheVector) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  MemorySection memorySection(size, content, initialPos);
  Memtype memtypeMock = parseMemType(validMemtypeGenerator());

  memorySection.addMemtype(memtypeMock);

  BOOST_CHECK_EQUAL(1, memorySection.getMemtypeVector().size());
}

BOOST_AUTO_TEST_CASE(displaySectionHeaderInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  MemorySection memorySection(size, content, initialPos);

  memorySection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_CASE(displaySectionContentInfo_doesNotFail) {
  int size = 8;
  auto *content = new uint8_t[size];
  int initialPos = 0;
  MemorySection memorySection(size, content, initialPos);

  memorySection.displaySectionHeaderInfo();
}

BOOST_AUTO_TEST_SUITE_END() // memsec_test
