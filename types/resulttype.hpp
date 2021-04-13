#ifndef ANTIWASM_RESULTTYPE_HPP
#define ANTIWASM_RESULTTYPE_HPP

#include <iostream>
#include <vector>

#include "../utils/leb128.hpp"
#include "valtype.hpp"

namespace antiwasm {

struct Resulttype {
  std::vector<Valtype> valtypeVector;
  unsigned int nBytes = 0;
  bool error = false;
};

/**
 * Parses and generates the parsed resulttype.
 * Adds error if cannot complete the parsing.
 * @param resultTypeContent
 * @return
 */
Resulttype parseResulttype(const uint8_t *resultTypeContent);

void displayResulttype(const Resulttype &resulttype);
} // namespace antiwasm

#endif // ANTIWASM_RESULTTYPE_HPP
