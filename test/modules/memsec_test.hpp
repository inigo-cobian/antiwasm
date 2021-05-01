#ifndef ANTIWASM_MEMSEC_TEST_HPP
#define ANTIWASM_MEMSEC_TEST_HPP

#include "memsec.hpp"
#include <boost/test/unit_test.hpp>

uint8_t *validMemtypeGenerator() {
  auto limitType = antiwasm::limit_types::limit_min_max;

  auto *memtypeContent = new uint8_t[3];
  memtypeContent[0] = limitType;
  memtypeContent[1] = 0x12, memtypeContent[2] = 0x5F;
  return memtypeContent;
}

#endif // ANTIWASM_MEMSEC_TEST_HPP
