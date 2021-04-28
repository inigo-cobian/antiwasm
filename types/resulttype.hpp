#ifndef ANTIWASM_RESULTTYPE_HPP
#define ANTIWASM_RESULTTYPE_HPP

#include "leb128.hpp"
#include "valtype.hpp"
#include <iostream>
#include <vector>

namespace antiwasm {

struct Resulttype : public ContentBlock {
  vector<Valtype> valtypeVector;
  unsigned int nBytes = 0;
};

/**
 * Parses and generates the parsed resulttype.
 * Adds error if cannot complete the parsing.
 * @param resultTypeContent
 * @return
 */
Resulttype parseResulttype(const uint8_t *resultTypeContent);
} // namespace antiwasm

#endif // ANTIWASM_RESULTTYPE_HPP
