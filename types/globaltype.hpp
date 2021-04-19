#ifndef ANTIWASM_GLOBALTYPE_HPP
#define ANTIWASM_GLOBALTYPE_HPP

#include "mut.hpp"
#include "valtype.hpp"

namespace antiwasm {

struct Globaltype : public ContentBlock {
  Valtype valtype;
  Mut mut;

  void displayError() override;
  void displayContentInfo() override;
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
