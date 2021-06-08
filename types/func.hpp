#ifndef ANTIWASM_FUNC_HPP
#define ANTIWASM_FUNC_HPP

#include "locals.hpp"
#include "expression.hpp"
#include "leb128.hpp"
#include <vector>
#include <cstdint>
#include <string>

namespace antiwasm {
struct Func : public ContentBlock {
  std::vector<Locals> localsVec;
  Expression expr;

  Func(std::vector<Locals> localsVec_, Expression expr_);
  [[nodiscard]] std::string getAsText() const;
};

/**
 * Parses and generates the parsed Func.
 * Adds error if cannot complete the parsing.
 * @param funcContent
 * @return
 */
Func parseFunc(const uint8_t *funcContent);

} // namespace antiwasm

#endif // ANTIWASM_FUNC_HPP
