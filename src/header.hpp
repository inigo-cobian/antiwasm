#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

namespace antiwasm {
    char checkMagicNumber(unsigned char* header);
    char checkVersion(unsigned char* version);
}

#endif
