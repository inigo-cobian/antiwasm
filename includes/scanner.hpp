#ifndef SCANNER_HPP
#define SCANNER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include "lexems.hpp"
#include "header.hpp"
#include "module.hpp"
#include "driver.hpp"
#include <boost/log/trivial.hpp>

namespace antiwasm {

    /* Function that begins to parse the file given as an argument */
    int parse(const char* classFile);

    typedef unsigned char uint8;

    const char INDEX_VERSION = 4;
    const char INDEX_SECTIONS = 8;
}

#endif