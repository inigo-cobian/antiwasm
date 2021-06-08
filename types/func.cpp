#include "func.hpp"

namespace antiwasm {

Func::Func(std::vector<Locals> localsVec_, Expression expr_) {}

std::string Func::getAsText() const {
  return nullptr;
}

Func parseFunc(const uint8_t *codeContent) {
  return Func{std::vector<Locals>(), Expression{}};
}

} // namespace antiwasm
