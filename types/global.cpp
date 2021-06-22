#include "global.hpp"

#include <utility>

namespace antiwasm {
std::string Global::getAsText() const {
  // TODO global
  std::stringstream globalAsText;

  globalAsText << "( global \n "
               << globaltype.getAsText()
               // TODO << " " << expr.getAsText();
               << "\n [expr] "
               << "\n)";

  return globalAsText.str();
}
Global::Global(Globaltype globaltype_, Expression expr_) : globaltype(std::move(globaltype_)), expr(std::move(expr_)) {}

Global parseGlobal(const uint8_t *globalContent) {
  Globaltype globaltype = parseGlobaltype(globalContent);
  if (globaltype.hasError()) {
    // TODO error
  }

  auto expr = parseExpression(&globalContent[BYTES_GLOBALTYPE]);
  if (expr.hasError()) {
    // TODO error
  }

  Global global{globaltype, expr};
  global.setNBytes(globaltype.getNBytes() + expr.getNBytes());
  return global;
}
} // namespace antiwasm