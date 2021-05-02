#ifndef ANTIWASM_TABLESEC_TEST_HPP
#define ANTIWASM_TABLESEC_TEST_HPP

#include "tablesec.hpp"
#include <boost/test/unit_test.hpp>

uint8_t *validTabletypeGenerator() {
  auto limitType = antiwasm::limit_types::limit_min_max;

  auto *tabletypeContent = new uint8_t[4];
  tabletypeContent[0] = limitType;
  tabletypeContent[1] = 0x12, tabletypeContent[2] = 0x5F;
  tabletypeContent[3] = antiwasm::Reftype::externref;

  return tabletypeContent;
}

#endif // ANTIWASM_TABLESEC_TEST_HPP
