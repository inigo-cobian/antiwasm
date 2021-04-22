#ifndef ANTIWASM_NAMEPARSER_HPP
#define ANTIWASM_NAMEPARSER_HPP

#include "contentBlock.hpp"
#include <string>

using namespace std;
namespace antiwasm {

struct UTF8_Name : public ContentBlock {
  string name;
  uint32_t nBytes;
};

UTF8_Name parseUTF8Name(const uint8_t *bytes, uint32_t size);

/**
 * Takes a continuation byte and validates if it has the correct format
 * ContByte is defined at the UTF-8 standard as 10bb'bbbb.
 * @param contByte
 * @return true if valid, false if otherwise
 */
bool validateUTF8ContinuationByte(const uint8_t contByte);

} // namespace antiwasm

#endif // ANTIWASM_NAMEPARSER_HPP
