#include "func.hpp"

namespace antiwasm {

Func::Func(std::vector<Locals> localsVec_, Expression expr_) : localsVec(localsVec_), expr(expr_) {
  if (localsVec.front().hasError()) {
    auto error = generateError(fatal, invalidLocalAtFunc, localsVec_.size());
    addError(error);
  } else if (expr.hasError()) {
    auto error = generateError(fatal, invalidExprAtFunc, 0);
    addError(error);
  }
}

std::string Func::getAsText() const { return std::string(); }

Func parseFunc(const uint8_t *funcContent) {
  uint32_t sizeOfLocalsVec = transformLeb128ToUnsignedInt32(funcContent);
  auto pos = sizeOfLeb128(funcContent);
  std::vector<Locals> localsVec;

  for (size_t i = 0; i < sizeOfLocalsVec; i++) {
    auto local = parseLocals(funcContent + pos);
    localsVec.push_back(local);
    pos += local.getNBytes();
    if (local.hasError())
      break;
  }

  auto expr = parseExpression(funcContent + pos);

  Func func{localsVec, expr};
  func.setNBytes(pos + expr.getNBytes());
  return func;
}

} // namespace antiwasm
