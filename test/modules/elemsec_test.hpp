#ifndef ANTIWASM_ELEMSEC_TEST_HPP
#define ANTIWASM_ELEMSEC_TEST_HPP

#include "elemsec.hpp"
#include <boost/test/unit_test.hpp>

antiwasm::Element generateElement() {
  auto *elementContent = new uint8_t[6];
  elementContent[0] = antiwasm::elem0;
  elementContent[1] = i32_const, elementContent[2] = 0x05, elementContent[3] = End; // expr
  elementContent[4] = 0x01, elementContent[5] = 0x00; // funcidxVec

  auto element = antiwasm::parseElement(elementContent);
  return element;
}

#endif // ANTIWASM_ELEMSEC_TEST_HPP
