#ifndef ANTIWASM_TABLETYPE_HPP
#define ANTIWASM_TABLETYPE_HPP

#include "limits.hpp"
#include "reftype.hpp"

struct Tabletype {
  Reftype reftype;
  Limit limit;
  bool error = false;
};

namespace antiwasm {
/**
 * Parses and generates the parsed tabletype.
 * Adds error if cannot complete the parsing.
 * @param tableTypeContent
 * @return
 */
Tabletype parseTableType(const uint8_t *tableTypeContent);

void displayTabletype(Tabletype tabletype);
} // namespace antiwasm

#endif // ANTIWASM_TABLETYPE_HPP
