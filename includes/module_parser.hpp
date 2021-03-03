#ifndef MODULE_PARSER_HPP
#define MODULE_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <boost/log/trivial.hpp>
#include "section_index.hpp"

namespace antiwasm {
    int parseNextSection(unsigned char sectionId, int sectionSize, unsigned char* sectionContent);

    int parseCustomSection(int sizeOfSection, unsigned char* sectionContent);
    int parseTypeSection(int sizeOfSection, unsigned char* sectionContent);
    int parseImportSection(int sizeOfSection, unsigned char* sectionContent);
    int parseFunctionSection(int sizeOfSection, unsigned char* sectionContent);
    int parseTableSection(int sizeOfSection, unsigned char* sectionContent);
    int parseMemorySection(int sizeOfSection, unsigned char* sectionContent);
    int parseGlobalSection(int sizeOfSection, unsigned char* sectionContent);
    int parseExportSection(int sizeOfSection, unsigned char* sectionContent);
    int parseStartSection(int sizeOfSection, unsigned char* sectionContent);
    int parseElementSection(int sizeOfSection, unsigned char* sectionContent);
    int parseCodeSection(int sizeOfSection, unsigned char* sectionContent);
    int parseDataSection(int sizeOfSection, unsigned char* sectionContent);
}

#endif
