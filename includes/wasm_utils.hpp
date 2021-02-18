#ifndef ANTIWASM_WASM_UTILS_HPP
#define ANTIWASM_WASM_UTILS_HPP
#include <cstdint>
#include <stdio.h>

char* bytesToHexChar(const char* signedLittleEndianBytes, int nBytes);
void singleByteToTwoHexChar(const uint8_t byte, char* destHexChar);
char getHexChar(unsigned char origin);

#endif //ANTIWASM_WASM_UTILS_HPP
