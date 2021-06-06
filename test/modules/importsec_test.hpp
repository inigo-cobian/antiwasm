#ifndef ANTIWASM_IMPORTSEC_TEST_HPP
#define ANTIWASM_IMPORTSEC_TEST_HPP

#include "importsec.hpp"
#include <boost/test/unit_test.hpp>

uint8_t *validImportFuncGenerator() {
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

uint8_t *validImportTableGenerator() {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto *importContent = new uint8_t[11];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = antiwasm::ImportDescType::ImportTable;
  importContent[10] = antiwasm::Reftype::externref;
  importContent[11] = antiwasm::limit_types::limit_min;
  importContent[12] = 0x02;

  return importContent;
}

uint8_t *validImportMemtypeGenerator() {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto typeidx = 0x01;
  auto *importContent = new uint8_t[12];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = antiwasm::ImportDescType::ImportMemtype;
  importContent[10] = antiwasm::limit_types::limit_min;
  importContent[11] = 0x02;

  return importContent;
}

uint8_t *validImportGlobalGenerator() {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto *importContent = new uint8_t[12];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = antiwasm::ImportDescType::ImportGlobaltype;
  importContent[10] = Mut::var_;
  importContent[11] = antiwasm::Reftype::externref;

  return importContent;
}

uint8_t *invalidImportGenerator() {
  auto sizeOfMod = 4;
  auto sizeOfName = 3;
  auto *importContent = new uint8_t[12];
  importContent[0] = sizeOfMod;
  importContent[1] = 't', importContent[2] = 'e', importContent[3] = 's', importContent[4] = 't';
  importContent[5] = sizeOfName;
  importContent[6] = 'F', importContent[7] = 'o', importContent[8] = 'o';
  importContent[9] = antiwasm::ImportDescType::invalidImportDescType;
  importContent[10] = Mut::var_;
  importContent[11] = antiwasm::Reftype::externref;

  return importContent;
}

#endif // ANTIWASM_IMPORTSEC_TEST_HPP
