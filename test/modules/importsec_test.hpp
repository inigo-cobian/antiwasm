#ifndef ANTIWASM_IMPORTSEC_TEST_HPP
#define ANTIWASM_IMPORTSEC_TEST_HPP

#include "importsec.hpp"
#include <boost/test/unit_test.hpp>

uint8_t *validImportGenerator() {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;

  auto *importContent = new uint8_t[11];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = antiwasm::ImportDescType::ImportFunc;
  importContent[10] = typeidx;
  return importContent;
}

#endif // ANTIWASM_IMPORTSEC_TEST_HPP
