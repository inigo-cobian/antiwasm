#include "memtype.hpp"

namespace antiwasm {
Memtype::Memtype(Limit p_limit) : limit(p_limit) {}

Memtype parseMemType(const uint8_t *memTypeContent) {
  Limit memtypeLimit = parseLimits(memTypeContent);
  Memtype memtype{memtypeLimit};
  if (memtypeLimit.hasError()) {
    if (memtypeLimit.getError()->errorType == unrecognizedHeaderAtLimit) {
      auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, 0);
      memtype.addError(error);
    } else if (memtypeLimit.getError()->errorType == unrecognizedMinGreaterThanMaxAtLimit) {
      auto error = generateError(fatal, unrecognizedMinGreaterThanMaxLimitAtTabletype, 0);
      memtype.addError(error);
    }
  }
  return memtype;
}
std::string Memtype::getAsText() const {
  std::stringstream memtypeAsText;
  memtypeAsText << "( memory $index"
                << " "; // TODO index
  if (limit.type == limit_min) {
    memtypeAsText << limit.min << " )\n";
  } else if (limit.type == limit_min_max) {
    memtypeAsText << limit.min << " " << limit.max << " )\n";
  } else {
    memtypeAsText << "has invalid content )\n";
  }
  return memtypeAsText.str();
}
} // namespace antiwasm
