#ifndef MODULE_PARSER_HPP
#define MODULE_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include "driver.hpp"
#include "header.hpp"
#include "leb128.hpp"
#include "module.hpp"
#include "section_parser.hpp"
#include "contentBlock.hpp"
#include <boost/log/trivial.hpp>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

namespace antiwasm {

/**
 * Begins to parse the file given as an argument
 * @param classFile
 * @return 0 if the parsing was correct, otherwise it returns another value.
 * TODO which ones
 */
int parse(const char *classFile);

} // namespace antiwasm

#endif // MODULE_PARSER_HPP
