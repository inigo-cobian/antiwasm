#ifndef ANTIWASM_VALTYPE_HPP
#define ANTIWASM_VALTYPE_HPP

#include "contentBlock.hpp"
#include "numtype.hpp"
#include "reftype.hpp"

namespace antiwasm {

enum valtype_type { valtype_numtype, valtype_reftype, valtype_error };

struct Valtype : public ContentBlock {
  valtype_type type;
  // TODO explain in the docs that they are two elements to keep the code Æ s t h e t i c
  Numtype numtype;
  Reftype reftype;

  void displayError() override;
  void displayContentInfo() override;
};

/**
 * Gets a byte and returns the equivalent Valtype.
 * Adds error if cannot complete the parsing.
 * @param valtypeContent
 * @return
 */
Valtype parseValtype(uint8_t valtypeContent);

} // namespace antiwasm
#endif // ANTIWASM_VALTYPE_HPP
