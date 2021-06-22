#ifndef MODULE_PARSER_HPP
#define MODULE_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include "contentBlock.hpp"
#include "driver.hpp"
#include "header.hpp"
#include "leb128.hpp"
#include "module.hpp"
#include "section_parser.hpp"
#include <boost/log/trivial.hpp>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <mpi.h>

namespace antiwasm {

static std::map<int, std::vector<SectionHeader>> mapThreadSections;

/**
 * Begins to parse the file given as an argument
 * @param classFile
 * @return 0 if the parsing was correct, otherwise it returns another value.
 */
int parse(const char *classFile);

/**
 * Validates the magic number and version of the module
 * @param module
 * @return returns true if it is valid, false otherwise
 */
bool validateModuleHeader(Module &module);

/**
 * Begins to parse the module given as an argument
 * @param module
 * @return returns true if it can complete de parsing, false otherwise
 */
bool parseSectionHeaderMap(Module &module);

/**
 * Shares the sections to four different threads and parses them in parallel
 * @param module
 * @return returns true if it can complete de parsing, false otherwise
 */
bool multithreadParsing(Module &module);

/**
 * Parses the module in sequence
 * @param module
 * @return returns true if it can complete de parsing, false otherwise
 */
bool singlethreadParsing(Module &module);

void addSectionHeaderToThread(int thread, const SectionHeader& sectionHeader);

} // namespace antiwasm

#endif // MODULE_PARSER_HPP
