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
    static const unsigned char LIMIT_MIN = 0x00;
    static const unsigned char LIMIT_MIN_MAX = 0x01;
    static const unsigned char CODE_LIMIT_MIN = 2;
    static const unsigned char CODE_LIMIT_MIN_MAX = 3;

    Limit *parseLimits(const unsigned char *);

    void parseLimitMin(); //TODO

    void parseLimitMinMax(); //TODO
}

#endif
