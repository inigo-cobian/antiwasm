#ifndef ANTIWASM_MEMTYPE_HPP
#define ANTIWASM_MEMTYPE_HPP

#include "limits.hpp"
#include <sstream>

namespace antiwasm {

struct Memtype : public ContentBlock {
  Limit limit;

  Memtype(Limit p_limit) : limit(p_limit) {}
  std::string getAsText() const;
};

/**
 * Parses and generates the parsed memtype.
 * Adds error if cannot complete the parsing.
 * @param memTypeContent
 * @return
 */
Memtype parseMemType(const uint8_t *memTypeContent);
} // namespace antiwasm

#endif // ANTIWASM_MEMTYPE_HPP
