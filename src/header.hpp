#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

namespace antiwasm {
    char checkMagicNumber(unsigned char* header);
    char checkVersion(unsigned char* version);
}
