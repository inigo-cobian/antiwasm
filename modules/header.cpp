#include "header.hpp"

namespace antiwasm {
    bool checkMagicNumber(const uint8_t *header) {
        if (header[0] == 0x00 && header[1] == 0x61 && header[2] == 0x73 && header[3] == 0x6D) {
            BOOST_LOG_TRIVIAL(debug) << "[header] Magic header found";
            return true;
        } else {
            BOOST_LOG_TRIVIAL(error) << "[header] This file has no magic header." << std::endl << "Compilation failed.";
            printf("%02x %02x %02x %02x\n", header[0], header[1], header[2], header[3]);
            return false;
        }
    }

    bool checkVersion(const uint8_t *version) {
        if (version[0] == 0x01 && version[1] == 0x00 && version[2] == 0x00 && version[3] == 0x00) {
            BOOST_LOG_TRIVIAL(debug) << "[header] Version 1.0";
            return true;
        } else {
            BOOST_LOG_TRIVIAL(warning) << "[header] Unknown version. Some functionalities might not be supported.";
            return false;
        }
    }
}
