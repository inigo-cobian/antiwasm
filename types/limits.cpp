#include "limits.hpp"

namespace antiwasm {
Limit::Limit(limit_types p_limitTypes, uint32_t p_min, uint32_t p_nBytes_) : type(p_limitTypes), min(p_min), max(0) {
  setNBytes(p_nBytes_);
}

Limit::Limit(limit_types p_limitTypes, uint32_t p_min, uint32_t p_max, uint32_t p_nBytes_)
    : type(p_limitTypes), min(p_min), max(p_max) {
  setNBytes(p_nBytes_);
}

Limit parseLimits(const uint8_t *limitSection) {
  BOOST_LOG_TRIVIAL(debug) << "[Limit] Parsing a new Limit";

  if (limitSection[0] == limit_types::limit_min) {
    BOOST_LOG_TRIVIAL(debug) << "[Tabletype] Parsing a new Tabletype";
    uint32_t min_ = transformLeb128ToUnsignedInt32(&limitSection[SIZE_OF_LIMIT_TYPE]);
    auto nBytes = sizeOfLeb128(&limitSection[SIZE_OF_LIMIT_TYPE]);
    return parseLimitMin(min_, nBytes);
  }
  if (limitSection[0] == limit_types::limit_min_max) {
    uint32_t min_ = transformLeb128ToUnsignedInt32(&limitSection[SIZE_OF_LIMIT_TYPE]);
    auto nBytes = sizeOfLeb128(&limitSection[SIZE_OF_LIMIT_TYPE]);
    uint32_t max_ = transformLeb128ToUnsignedInt32(&limitSection[SIZE_OF_LIMIT_TYPE + nBytes]);
    nBytes += sizeOfLeb128(&limitSection[SIZE_OF_LIMIT_TYPE + nBytes]);

    return parseLimitMinMax(min_, max_, nBytes);
  } else {
    // TODO better error, ¿maybe get a msg?
    std::cout << "limit raro" << std::endl;
    Limit limit = generateErrorLimit();
    return limit;
  }
}

Limit parseLimitMin(const uint32_t min_, const uint32_t p_nBytes) {
  Limit limit{limit_min, min_, p_nBytes};

  BOOST_LOG_TRIVIAL(debug) << "[Limit] New limit [" << std::hex << limit.min << "-MAX]";
  BOOST_LOG_TRIVIAL(debug) << "[Limit] nBytes: " << limit.getNBytes();
  return limit;
}

Limit parseLimitMinMax(const uint32_t min_, const uint32_t max_, const uint32_t p_nBytes) {
  Limit limit{limit_min_max, min_, max_, p_nBytes};
  if (checkIfLimitIsNotValid(min_, max_)) {
    auto error = generateError(fatal, unrecognizedMinGreaterThanMaxAtLimit, 0);
    limit.addError(error);
  }
  if (limit.hasError()) {
    std::cout << "Min-Max: " << (int)limit.min << "-" << (int)limit.max << std::endl;
  }

  BOOST_LOG_TRIVIAL(debug) << "[limits] New limit [" << std::hex << limit.min << "-" << std::hex << limit.max << "]";
  BOOST_LOG_TRIVIAL(debug) << "[Limit] nBytes: " << limit.getNBytes();
  return limit;
}

Limit generateErrorLimit() {
  Limit limit(limit_error, 0, 0);
  auto error = generateError(fatal, unrecognizedHeaderAtLimit, 0);
  limit.addError(error);
  return limit;
}

bool checkIfLimitIsNotValid(const uint32_t min_, const uint32_t max_) { return min_ > max_; }

void Limit::displayContentInfo() {
  if (type == limit_min) {
    std::cout << "[" << std::hex << min << "-MAX]";
  } else if (type == limit_min_max) {
    std::cout << "[" << std::hex << min << "-" << max << "]";
  } else {
    displayError();
  }
}
void Limit::displayError() {
  // TODO
}
} // namespace antiwasm
