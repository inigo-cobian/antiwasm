#ifndef SCANNER_HPP
#define SCANNER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include "header.hpp"
#include "module_parser.hpp"
#include "driver.hpp"
#include <boost/log/trivial.hpp>

namespace antiwasm {

    /* Function that begins to parse the file given as an argument */
    int parse(const char* classFile);

    static const char INDEX_VERSION = 4;
    static const char INDEX_SECTIONS = 8;
}

#endif
