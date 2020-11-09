#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
#include "section_index.hpp"
#include "driver.hpp"
#include "val_type.hpp"

namespace antiwasm {
    size_t parseSections(unsigned char* buffer);
    unsigned char* getSection(unsigned char sizeOfSection);

    unsigned char* parseTypeSection(unsigned char sizeOfSection);
    unsigned char* parseFunctionSection(unsigned char sizeOfSection);
}

#endif
