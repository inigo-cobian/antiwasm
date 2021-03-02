#ifndef MODULE_PARSER_HPP
#define MODULE_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <boost/log/trivial.hpp>
#include "section_index.hpp"

namespace antiwasm {
    int parseNextSection(unsigned char sectionId, int sectionSize, unsigned char* sectionContent); //TODO ¿mover a otro fichero?

    unsigned char* parseCustomSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseTypeSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseImportSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseFunctionSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseTableSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseMemorySection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseGlobalSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseExportSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseStartSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseElementSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseCodeSection(int sizeOfSection, unsigned char* sectionContent);
    unsigned char* parseDataSection(int sizeOfSection, unsigned char* sectionContent);
}

#endif
