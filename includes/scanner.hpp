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
#include "module.hpp"
#include <boost/log/trivial.hpp>

namespace antiwasm {

    /**
     * Begins to parse the file given as an argument
     * @param classFile
     * @return 0 if the parsing was correct, otherwise it returns another value. TODO which ones
     */
    int parse(const char *classFile);

}

#endif
