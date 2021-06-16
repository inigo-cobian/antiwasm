#ifndef ANTIWASM_LOCALS_HPP
#define ANTIWASM_LOCALS_HPP

#include "leb128.hpp"
#include "valtype.hpp"
#include <cstdint>

namespace antiwasm {
struct Locals : public ContentBlock {
  uint32_t n;
  Valtype valtype;

  Locals(uint32_t n_, Valtype valtype_);
  [[nodiscard]] std::string getAsText() const;
};

/**
 * Parses and generates the parsed Locals.
 * Adds error if cannot complete the parsing.
 * @param localsContent
 * @return
 */
Locals parseLocals(const uint8_t *localsContent);

} // namespace antiwasm

#endif // ANTIWASM_LOCALS_HPP
