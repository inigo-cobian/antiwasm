#ifndef ANTIWASM_NAMEPARSER_HPP
#define ANTIWASM_NAMEPARSER_HPP

#include "contentBlock.hpp"
#include <string>

using namespace std;
namespace antiwasm {

struct UTF8Name : public ContentBlock {
  string name;
  uint32_t nBytes;
};

/**
 * Generates a UTF8Name from a set of bytes and validates it.
 * The bytes represent the name and the nBytes the number of bytes.
 * During the validation adds an error if the string is not UTF8 valid.
 * Both, correct and incorrect strings create a UTF8.name
 * @param bytes
 * @param nBytes
 * @return UTF8Name
 */
UTF8Name parseUTF8Name(const uint8_t *bytes, uint32_t nBytes);

/**
 * Takes a continuation byte and validates if it has the correct format
 * ContByte is defined at the UTF-8 standard as 10bb'bbbb.
 * @param contByte
 * @return true if valid, false if otherwise
 */
bool validateUTF8ContinuationByte(uint8_t contByte);

} // namespace antiwasm

#endif // ANTIWASM_NAMEPARSER_HPP
