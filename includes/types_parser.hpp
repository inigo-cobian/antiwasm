#ifndef TYPES_PARSER_HPP
#define TYPES_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <string>
#include <cstring>
#include <locale>
#include <boost/log/trivial.hpp>
#include "../includes/expression_parser.hpp"

namespace antiwasm {
    void parseFuncTypeVec(unsigned char* funcTypeVecSection);
    void parseFuncType(unsigned char* funcTypeSection, int &pointer);
    void parseResultType(unsigned char* resultTypeSection, int &pointer);
    void parseValType(unsigned char valType);
    void parseGlobalVec(unsigned char *globalSectionBuffer);
    void parseElementVec(unsigned char *elementVec);
    void parseFuncIdxVec(unsigned char* funcIdxVec, int &pointer);
    void parseDataVec(unsigned char *dataVec);
    void parseByteVec(unsigned char * byteVec, int pointer);
    void parseImportVec(unsigned char *importVec);
    void parseName(char* nameBuffer, int &pointer);
    void parseImportDesc(unsigned char* importDesc, int &pointer);
    void parseExportVec(unsigned char *exportVec);
    void parseExportDesc(unsigned char* exportDesc, int &pointer);
    void parseStart(unsigned char startFunc);
}

#endif
