#ifndef ANTIWASM_FUNCTYPE_HPP
#define ANTIWASM_FUNCTYPE_HPP

#include "contentBlock.hpp"
#include "resulttype.hpp"
#include <iostream>

namespace antiwasm {

const uint8_t FUNCTYPE_HEADER = 0x60;

struct Functype : public ContentBlock {
  Resulttype parameterType;
  // TODO check if this name has the same meaning in the docs
  Resulttype returnType;
};

const unsigned int BYTES_HEADER_FUNCTYPE = 1;

/**
 * Parses and generates the parsed functype.
 * Adds error if cannot complete the parsing.
 * @param funcTypeContent
 * @return
 */
Functype parseFunctype(const uint8_t *funcTypeContent);
} // namespace antiwasm

#endif // ANTIWASM_FUNCTYPE_HPP
