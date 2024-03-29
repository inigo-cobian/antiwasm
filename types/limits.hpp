#ifndef LIMITS_HPP
#define LIMITS_HPP

#define BOOST_LOG_DYN_LINK 1

#include "contentBlock.hpp"
#include "displayable.hpp"
#include "leb128.hpp"
#include <boost/log/trivial.hpp>
#include <cstdint>
#include <iostream>

namespace antiwasm {

enum limit_types : uint8_t { limit_min = 0x00, limit_min_max = 0x01, limit_error = 0xFF };

struct Limit : public ContentBlock, Displayable {
  limit_types type;
  uint32_t min;
  uint32_t max;
  int nBytes = 0;

  /**
   * Contructor for limits with type min.
   * @param p_limitTypes
   * @param p_min
   * @param p_nBytes_
   */
  Limit(limit_types p_limitTypes, uint32_t p_min, uint32_t p_nBytes_);

  /**
   * Constructor for limits with type min-max
   * @param p_limitTypes
   * @param p_min
   * @param p_max
   * @param p_nBytes_
   */
  Limit(limit_types p_limitTypes, uint32_t p_min, uint32_t p_max, uint32_t p_nBytes_);

  void displayError() override;
  void displayContentInfo() override;
};

const unsigned int SIZE_OF_LIMIT_TYPE = 1;
const auto BYTES_LIMIT_MIN = 2;
const auto BYTES_LIMIT_MIN_MAX = 3;

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
Limit parseLimitMin(uint32_t min_, uint32_t p_nBytes);

/**
 * Generates a limit [min-max].
 * Adds error if cannot complete the parsing.
 * @param min_
 * @param max_
 * @return
 */
Limit parseLimitMinMax(uint32_t min_, uint32_t max_, uint32_t p_nBytes);

/**
 * Generates a limit with error type.
 * @return Error limit
 */
Limit generateErrorLimit();

/**
 * Checks if the limit range is valid.
 * @param min_
 * @param max_
 * @return true if the limit is not valid, false if it is
 */
bool checkIfLimitIsNotValid(uint32_t min_, uint32_t max_);
} // namespace antiwasm

#endif
