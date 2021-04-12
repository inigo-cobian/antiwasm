#include "wasm_utils.hpp"

namespace antiwasm {
char *bytesToHexChar(uint8_t *signedLittleEndianBytes, int nBytes) {
  char *formattedHexBytes = new char(nBytes * 2);
  for (int i = 0; i < nBytes; i++) {
    singleByteToTwoHexChar(signedLittleEndianBytes[i],
                           &formattedHexBytes[i * 2]);
  }
  return formattedHexBytes;
}

void singleByteToTwoHexChar(const uint8_t byte, char *destHexChar) {
  if (byte >= 0x10) {
    uint8_t firstChar = byte >> 4;
    destHexChar[0] = getHexChar(firstChar);
  } else {
    destHexChar[0] = '0';
  }
  uint8_t secondChar = byte & 0x00000f;
  destHexChar[1] = getHexChar(secondChar);
}

char getHexChar(uint8_t origin) {
  if (origin < 0xA) {
    return '0' + origin;
  } else {
    return 'A' + origin - 0xA;
  }
}

} // namespace antiwasm