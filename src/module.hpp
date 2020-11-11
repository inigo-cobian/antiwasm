#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
#include "section_index.hpp"
#include "driver.hpp"
#include "val_type.hpp"
#include "limits.hpp"

namespace antiwasm {
    size_t parseSections(unsigned char* buffer);
    unsigned char* getSection(unsigned char sizeOfSection);

    unsigned char* parseCustomSection(unsigned char sizeOfSection);
    unsigned char* parseTypeSection(unsigned char sizeOfSection);
    unsigned char* parseImportSection(unsigned char sizeOfSection);
    unsigned char* parseFunctionSection(unsigned char sizeOfSection);
    unsigned char* parseTableSection(unsigned char sizeOfSection);
    unsigned char* parseMemorySection(unsigned char sizeOfSection);
    unsigned char* parseGlobalSection(unsigned char sizeOfSection);
    unsigned char* parseExportSection(unsigned char sizeOfSection);
    unsigned char* parseStartSection(unsigned char sizeOfSection);
    unsigned char* parseElementSection(unsigned char sizeOfSection);
    unsigned char* parseCodeSection(unsigned char sizeOfSection);
    unsigned char* parseDataSection(unsigned char sizeOfSection);

}

#endif
