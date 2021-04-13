#ifndef ANTIWASM_GLOBALTYPE_HPP
#define ANTIWASM_GLOBALTYPE_HPP

#include "mut.hpp"
#include "valtype.hpp"

namespace antiwasm {

struct Globaltype {
  Valtype valtype;
  Mut mut;
  bool error = false;
};

/**
 * Parses and generates the parsed globaltype.
 * Adds error if cannot complete the parsing.
 * @param globaltypeContent
 * @return
 */
Globaltype parseGlobaltype(const uint8_t *globaltypeContent);
} // namespace antiwasm

#endif // ANTIWASM_GLOBALTYPE_HPP
