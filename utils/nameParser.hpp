#ifndef ANTIWASM_NAMEPARSER_HPP
#define ANTIWASM_NAMEPARSER_HPP

#include <string>

using namespace std;
namespace antiwasm {

string parseUTF8Name(const uint8_t *bytes);

} // namespace antiwasm

#endif // ANTIWASM_NAMEPARSER_HPP
