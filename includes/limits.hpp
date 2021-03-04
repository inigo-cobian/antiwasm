#ifndef LIMITS_HPP
#define LIMITS_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <boost/log/trivial.hpp>

namespace antiwasm {
    static const unsigned char LIMIT_MIN = 0x00;
    static const unsigned char LIMIT_MIN_MAX = 0x01;
    static const unsigned char CODE_LIMIT_MIN = 2;
    static const unsigned char CODE_LIMIT_MIN_MAX = 3;

    bool parseLimitVec(unsigned char *limitVec);

    int getLimits(const unsigned char *);

}

#endif
