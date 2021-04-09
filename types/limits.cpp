#include "limits.hpp"

namespace antiwasm {
Limit parseLimits(const uint8_t *limitSection) {
  if (limitSection[0] == limit_types::limit_min) {
    uint32_t min_ =
        transformLeb128ToUnsignedInt32(&limitSection[SIZE_OF_LIMIT_TYPE]);
    auto nBytes = sizeOfLeb128(&limitSection[SIZE_OF_LIMIT_TYPE]);
    return parseLimitMin(min_, nBytes);
  }
  if (limitSection[0] == limit_types::limit_min_max) {
    uint32_t min_ =
        transformLeb128ToUnsignedInt32(&limitSection[SIZE_OF_LIMIT_TYPE]);
    auto nBytes = sizeOfLeb128(&limitSection[SIZE_OF_LIMIT_TYPE]);
    uint32_t max_ =
        transformLeb128ToUnsignedInt32(&limitSection[SIZE_OF_LIMIT_TYPE]);
    nBytes += sizeOfLeb128(&limitSection[SIZE_OF_LIMIT_TYPE + nBytes]);

    return parseLimitMinMax(min_, max_, nBytes);
  } else {
    // TODO better error, ¿maybe get a msg?
    std::cout << "limit raro" << std::endl;
    Limit limit{};
    limit.error = true;
    return limit;
  }
}

Limit parseLimitMin(const uint32_t min_, const int nBytes) {
  Limit limit{limit_min, min_, 0, nBytes, false};

  BOOST_LOG_TRIVIAL(info) << "[limits] New limit [" << std::hex << limit.min
                          << "-MAX]";
  return limit;
}

Limit parseLimitMinMax(const uint32_t min_, const uint32_t max_,
                       const int nBytes) {
  Limit limit{limit_min_max, min_, max_, nBytes, false};
  limit.error = checkIfLimitIsNotValid(min_, max_);
  if (limit.error)
    std::cout << "Min-Max: " << (int)limit.min << "-" << (int)limit.max
              << std::endl;

  BOOST_LOG_TRIVIAL(info) << "[limits] New limit [" << std::hex << limit.min
                          << "-" << std::hex << limit.max << "]";

  return limit;
}

bool checkIfLimitIsNotValid(const uint32_t min_, const uint32_t max_) {
  return min_ > max_;
}

void displayLimits(Limit limit) {
  if (limit.type == limit_min) {
    std::cout << "[" << std::hex << limit.min << "-MAX]";
  } else if (limit.type == limit_min_max) {
    std::cout << "[" << std::hex << limit.min << "-" << limit.max << "]";
  } else {
    std::cout << "error limit";
  }
}
} // namespace antiwasm
