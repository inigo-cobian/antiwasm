#ifndef HEADER_HPP
#define HEADER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <boost/log/trivial.hpp>

namespace antiwasm {
    char checkMagicNumber(unsigned char* header);
    char checkVersion(unsigned char* version);
}

#endif
