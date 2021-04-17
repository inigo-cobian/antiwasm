#ifndef ANTIWASM_TABLETYPE_HPP
#define ANTIWASM_TABLETYPE_HPP

#include "limits.hpp"
#include "reftype.hpp"

namespace antiwasm {

struct Tabletype : public ContentBlock {
  Reftype reftype;
  Limit limit;

  void displayError() override;
  Tabletype(Reftype p_reftype, Limit p_limit) : reftype(p_reftype), limit(p_limit){};
};

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
