#ifndef HEADER_HPP
#define HEADER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <boost/log/trivial.hpp>

namespace antiwasm {
    /**
     * Checks if the module has the magic number.
     * Magic number is defined as .asm (0x00 0x61 0x73 0x6d).
     * @param header
     * @return true if has the magic number, false if it does not.
     */
    bool checkMagicNumber(const unsigned char *header);

    /**
     * Checks if the module is of the current version (1.0)
     * Currently there is only one version, defined as (0x01 0x00 0x00 0x00)
     * @param version
     * @return true if has the version is recognized, false if it is not.
     */
    bool checkVersion(const unsigned char *version);
}

#endif
