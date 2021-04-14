#ifndef ANTIWASM_MEMTYPE_HPP
#define ANTIWASM_MEMTYPE_HPP

#include "limits.hpp"

namespace antiwasm {

struct Memtype {
  Limit limit;
};

/**
 * Parses and generates the parsed memtype.
 * Adds error if cannot complete the parsing.
 * @param memTypeContent
 * @return
 */
Memtype parseMemType(const uint8_t *memTypeContent);

void displayMemtype(Memtype memtype);
} // namespace antiwasm

#endif // ANTIWASM_MEMTYPE_HPP
