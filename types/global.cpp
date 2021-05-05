#include "global.hpp"

namespace antiwasm {
std::string Global::getAsText() const {
  // TODO global
  return std::string();
}

Global parseGlobal(const uint8_t *globalContent) {
  Globaltype globaltype = parseGlobaltype(globalContent);
  if (globaltype.hasError()) {
    // TODO error
  }

  auto expr = parseExpression(&globalContent[BYTES_GLOBALTYPE]);
  if (expr.hasError()) {
    // TODO error
  }

  return Global{globaltype, expr};
}

} // namespace antiwasm