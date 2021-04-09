#ifndef LIMITS_HPP
#define LIMITS_HPP

#define BOOST_LOG_DYN_LINK 1

#include <boost/log/trivial.hpp>
#include <cstdint>
#include <iostream>

#include "../utils/leb128.hpp"

enum limit_types : uint32_t { limit_min = 0x00, limit_min_max = 0x01 };

struct Limit {
  limit_types type;
  uint32_t min;
  uint32_t max;
  int nBytes = 0;
  bool error = false;
};

const unsigned int SIZE_OF_LIMIT_TYPE = 1;
const auto BYTES_LIMIT_MIN = 2;
const auto BYTES_LIMIT_MIN_MAX = 3;

namespace antiwasm {
/**
 * Parses and generates the parsed limit.
 * Adds error if cannot complete the parsing.
 * @param limitSection
 * @return
 */
Limit parseLimits(const uint8_t *limitSection);

/**
 * Generates a limit [min_-inf].
 * @param min_
 * @return
 */
Limit parseLimitMin(const uint32_t min_, const int nBytes);

/**
 * Generates a limit [min-max].
 * Adds error if cannot complete the parsing.
 * @param min_
 * @param max_
 * @return
 */
Limit parseLimitMinMax(uint32_t min_, const uint32_t max_, const int nBytes);

/**
 * Checks if the limit range is valid.
 * @param min_
 * @param max_
 * @return true if the limit is not valid, false if it is
 */
bool checkIfLimitIsNotValid(const uint32_t min_, const uint32_t max_);

void displayLimits(Limit limit);
} // namespace antiwasm

#endif
