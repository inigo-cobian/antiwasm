#ifndef ANTIWASM_TYPESEC_TEST_HPP
#define ANTIWASM_TYPESEC_TEST_HPP

#include "typesec.hpp"
#include <boost/test/unit_test.hpp>

uint8_t *validFunctypeGenerator() {
  auto *functypeContent = new uint8_t[6];
  functypeContent[0] = antiwasm::FUNCTYPE_HEADER;
  functypeContent[1] = 2, functypeContent[2] = antiwasm::Numtype::i32, functypeContent[3] = antiwasm::Reftype::funref;
  functypeContent[4] = 1, functypeContent[5] = antiwasm::Numtype::f64;

  return functypeContent;
}

#endif // ANTIWASM_TYPESEC_TEST_HPP
