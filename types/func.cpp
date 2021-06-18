#include "func.hpp"

#include <utility>

namespace antiwasm {

Func::Func(std::vector<Locals>  localsVec_, Expression expr_) : localsVec(std::move(localsVec_)), expr(std::move(expr_)) {
  BOOST_LOG_TRIVIAL(trace) << "[func] At Func constructor. Size of localsVec [" << localsVec.size() << "]. NBytes at expr [" << expr.getNBytes() << "]";
  if (!localsVec.empty() && localsVec.back().hasError()) {
    BOOST_LOG_TRIVIAL(debug) << "[func] Func has error invalidLocalAtFunc at pos [" << localsVec.size() << "]";
    auto error = generateError(fatal, invalidLocalAtFunc, localsVec.size());
    addError(error);
  } else if (expr.hasError()) {
    BOOST_LOG_TRIVIAL(debug) << "[func] Func has error invalidExprAtFunc";
    auto error = generateError(fatal, invalidExprAtFunc, 0);
    addError(error);
  }
}

std::string Func::getAsText() const {
  std::stringstream funcAsText;

  std::for_each(localsVec.begin(), localsVec.end(),
                [&funcAsText](const Locals &locals) mutable {
                  funcAsText << locals.getAsText() << "\n";
                });
  funcAsText << " [expr] "; // TODO expr as text

  return funcAsText.str();
}

Func parseFunc(const uint8_t *funcContent) {
  uint32_t sizeOfLocalsVec = transformLeb128ToUnsignedInt32(funcContent);
  size_t pos = sizeOfLeb128(funcContent);
  std::vector<Locals> localsVec;
  BOOST_LOG_TRIVIAL(debug) << "[func] LocalsVec has size [" << sizeOfLocalsVec << "] at pos [" << pos << "]";

  bool errorAtLocal = false;
  for (size_t i = 0; i < sizeOfLocalsVec; i++) {
    auto local = parseLocals(funcContent + pos);
    localsVec.push_back(local);
    BOOST_LOG_TRIVIAL(trace) << "[func] Added a new local [" << i << "] at localsVec";
    pos += local.getNBytes();
    if (local.hasError()) {
      errorAtLocal = true;
      BOOST_LOG_TRIVIAL(error) << "[func] local has error at pos [" << pos << "]";
      break;
    }
  }

  BOOST_LOG_TRIVIAL(trace) << "[func] Parsing expression for func at pos [" << pos << "]";
  Expression expr{};
  if (!errorAtLocal)
    expr = parseExpression(funcContent + pos);

  Func func{localsVec, expr};

  func.setNBytes(pos + expr.getNBytes());
  BOOST_LOG_TRIVIAL(trace) << "[func] Created func with size [" << func.getNBytes() << "]";
  return func;
}

} // namespace antiwasm
