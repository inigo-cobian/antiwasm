#ifndef LIMITS_HPP
#define LIMITS_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <cstdint>
#include <boost/log/trivial.hpp>

enum limit_types : uint32_t {
    limit_min = 0x00,
    limit_min_max = 0x01
};

struct Limit {
    limit_types type;
    uint32_t min;
    uint32_t max;
    bool error = false; //TODO
};

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
    Limit parseLimitMin(const uint32_t min_);

    /**
     * Generates a limit [min-max].
     * Adds error if cannot complete the parsing.
     * @param min_
     * @param max_
     * @return
     */
    Limit parseLimitMinMax(const uint32_t min_, const uint32_t max_);

    /**
     * Checks if the limit range is valid.
     * @param min_
     * @param max_
     * @return true if the limit is not valid, false if it is
     */
    bool checkIfLimitIsNotValid(const uint32_t min_, const uint32_t max_);
}

#endif
