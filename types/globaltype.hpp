#ifndef ANTIWASM_GLOBALTYPE_HPP
#define ANTIWASM_GLOBALTYPE_HPP

#include "mut.hpp"
#include "valtype.hpp"
#include <sstream>

namespace antiwasm {

struct Globaltype : public ContentBlock {
  Valtype valtype;
  Mut mut;

  string getAsText() const;
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
