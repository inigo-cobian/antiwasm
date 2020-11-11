#ifndef LIMITS_HPP
#define LIMITS_HPP

#include <iostream>

namespace antiwasm {
    static const unsigned char LIMIT_MIN = 0x00;
    static const unsigned char LIMIT_MIN_MAX = 0x01;

    int* getLimits(unsigned char*);

}

#endif
