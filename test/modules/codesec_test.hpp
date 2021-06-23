#ifndef ANTIWASM_CODESEC_TEST_HPP
#define ANTIWASM_CODESEC_TEST_HPP

#include "codesec.hpp"
#include <boost/test/unit_test.hpp>

antiwasm::Code generateCode() {
  auto *codeContent = new uint8_t[9];
  codeContent[0] = 0x08; // func size
  // first func
  codeContent[1] = 0x02; // localsVec size
  codeContent[2] = 0x01;
  codeContent[3] = antiwasm::Numtype::i32;
  codeContent[4] = 0x01;
  codeContent[5] = antiwasm::Numtype::f64;
  codeContent[6] = i32_const, codeContent[7] = 0x05, codeContent[8] = End; // expr

  auto code = antiwasm::parseCode(codeContent);
  return code;
}

#endif // ANTIWASM_CODESEC_TEST_HPP
