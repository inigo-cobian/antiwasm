#include "header.hpp"

namespace antiwasm {
    char checkMagicNumber(unsigned char* header) {
        if(header[0] == 0x00 && header[1] == 0x61 && header[2] == 0x73 && header[3] == 0x6D) {
            std::cout << "Magic header found" << std::endl;
            return true;
        }
        else {
            std::cout << "This file has no magic header." << std::endl << "Compilation failed." << std::endl;
            printf("%02x %02x %02x %02x\n", header[0], header[1], header[2], header[3]);
            return false;
        }
    }

    char checkVersion(unsigned char* version) {
        if(version[0] == 0x01 && version[1] == 0x00 && version[2] == 0x00 && version[3] == 0x00) {
            std::cout << "Version 1.0" << std::endl;
            return true;
        }
        else {
            std::cout << "Unknown version. Some functionalities might not be supported." << std::endl;
            return false;
        }
    }
}
