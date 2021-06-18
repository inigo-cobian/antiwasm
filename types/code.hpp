#ifndef ANTIWASM_CODE_HPP
#define ANTIWASM_CODE_HPP

#include "func.hpp"
#include <cstdint>
#include <sstream>
#include <string>
#include <utility>

namespace antiwasm {
struct Code : public ContentBlock {
  uint32_t size;
  Func func;

  Code(uint32_t size_, Func func_);
  [[nodiscard]] std::string getAsText(size_t index) const;
};

/**
 * Parses and generates the parsed Code.
 * Adds error if cannot complete the parsing.
 * @param codeContent
 * @return
 */
Code parseCode(const uint8_t *codeContent);

} // namespace antiwasm

#endif // ANTIWASM_CODE_HPP
