#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

namespace antiwasm {

    /* Function that begins to parse the file given as an argument */
    int parse(const char* classFile);

    typedef unsigned char uint8;

    const char INDEX_VERSION = 4;

}
