#ifndef ANTIWASM_TABLETYPE_HPP
#define ANTIWASM_TABLETYPE_HPP

#include "limits.hpp"
#include "reftype.hpp"
#include <sstream>
#include <utility>

namespace antiwasm {

struct Tabletype : public ContentBlock {
  Reftype reftype;
  Limit limit;

  Tabletype(Reftype p_reftype, Limit p_limit) : reftype(p_reftype), limit(std::move(p_limit)){};
  [[nodiscard]] std::string getAsText() const;
};

/**
 * Parses and generates the parsed tabletype.
 * Adds error if cannot complete the parsing.
 * @param tableTypeContent
 * @return
 */
Tabletype parseTableType(const uint8_t *tableTypeContent);
} // namespace antiwasm

#endif // ANTIWASM_TABLETYPE_HPP
