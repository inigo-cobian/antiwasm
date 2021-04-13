#ifndef ANTIWASM_FUNCTYPE_HPP
#define ANTIWASM_FUNCTYPE_HPP

#include <iostream>

#include "resulttype.hpp"

namespace antiwasm {

const uint32_t FUNCTYPE_HEADER = 0x60;

struct Functype {
  Resulttype parameterType;
  // TODO check if this name has the same meaning in the docs
  Resulttype returnType;
  int nBytes = 0;
  bool error = false;
};

const unsigned int BYTES_HEADER_FUNCTYPE = 1;

/**
 * Parses and generates the parsed functype.
 * Adds error if cannot complete the parsing.
 * @param funcTypeContent
 * @return
 */
Functype parseFunctype(const uint8_t *funcTypeContent);

void displayFunctype(Functype functype);
} // namespace antiwasm

#endif // ANTIWASM_FUNCTYPE_HPP
