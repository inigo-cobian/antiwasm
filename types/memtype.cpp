#include "memtype.hpp"

namespace antiwasm {
Memtype parseMemType(const uint8_t *memTypeContent) {
  Limit memtypeLimit = parseLimits(memTypeContent);
  Memtype memtype{memtypeLimit};
  if (memtypeLimit.hasError()) {
    if (memtypeLimit.getError()->errorType == unrecognizedHeaderAtLimit) {
      auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, 0);
      memtype.addError(error);
    } else if (memtypeLimit.getError()->errorType == unrecognizedMinGreaterThanMaxAtLimit) {
      auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, 0);
      memtype.addError(error);
    } else {
      auto error = generateError(fatal, unknown, 0);
      memtype.addError(error);
    }
  }
  return memtype;
}

void displayMemtype(Memtype memtype) {
  if (memtype.limit.type == limit_min) {
    std::cout << "  memtype: [" << memtype.limit.min << "-MAX]" << std::endl;
  } else if (memtype.limit.type == limit_min_max) {
    std::cout << "  memtype: [" << memtype.limit.min << "-" << memtype.limit.max << "]" << std::endl;
  } else {
    memtype.displayError();
  }
}
void Memtype::displayError() {
  // TODO
}
} // namespace antiwasm
