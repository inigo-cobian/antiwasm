#ifndef ANTIWASM_FUNCTYPE_TEST_HPP
#define ANTIWASM_FUNCTYPE_TEST_HPP

#include "functype.cpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace antiwasm;

uint8_t *generateFunctypeContent() {
  auto *functypeContent = new uint8_t[6];
  functypeContent[0] = FUNCTYPE_HEADER;
  functypeContent[1] = 2, functypeContent[2] = Numtype::i32, functypeContent[3] = Reftype::funref;
  functypeContent[4] = 1, functypeContent[5] = Numtype::f64;
  return functypeContent;
}

#endif // ANTIWASM_FUNCTYPE_TEST_HPP
