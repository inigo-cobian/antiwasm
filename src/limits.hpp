#ifndef LIMITS_HPP
#define LIMITS_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <boost/log/trivial.hpp>

namespace antiwasm {
    static const unsigned char LIMIT_MIN = 0x00;
    static const unsigned char LIMIT_MIN_MAX = 0x01;

    void parseLimitVec(unsigned char* limitVec);
    int getLimits(unsigned char*);

}

#endif
