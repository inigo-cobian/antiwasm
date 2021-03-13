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
    limit_types type; // 0x00 -> MIN, 0x01 -> MIN_MAX
    uint32_t min;
    uint32_t max;
    bool error = false;
};


namespace antiwasm {
    Limit *parseLimits(const unsigned char *limitSection);

    void parseLimitMin(); //TODO

    void parseLimitMinMax(); //TODO
}

#endif
