#ifndef ANTIWASM_GLOBAL_HPP
#define ANTIWASM_GLOBAL_HPP

#include "contentBlock.hpp"
#include "expression.hpp"
#include "globaltype.hpp"
#include <cstdint>

namespace antiwasm {
struct Global : public ContentBlock {
  Globaltype globaltype;
  Expression expr;

  Global(Globaltype globaltype_, Expression expr_);
  [[nodiscard]] static std::string getAsText();
};

/**
 * Parses and generates the parsed global.
 * Adds error if cannot complete the parsing.
 * @param globalContent
 * @return
 */
Global parseGlobal(const uint8_t *globalContent);

} // namespace antiwasm

#endif // ANTIWASM_GLOBAL_HPP
