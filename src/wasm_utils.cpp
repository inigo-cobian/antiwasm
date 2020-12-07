#include "../includes/wasm_utils.hpp"

unsigned char* bytesToHexChar(uint8_t* signedLittleEndianBytes, int nBytes)
{
    unsigned char* formattedHexBytes = new unsigned char(nBytes*2);
    for(int i = 0; i < nBytes; i++) {
        singleByteToTwoHexChar(signedLittleEndianBytes[i], &formattedHexBytes[i*2]);
    }
    return formattedHexBytes;
}

void singleByteToTwoHexChar(const uint8_t byte, unsigned char* destHexChar)
{
    if(byte >= 0x10) {
        uint8_t firstChar = byte >> 4;
        destHexChar[0] = getHexChar(firstChar);
    } else {
        destHexChar[0] = '0';
    }
    uint8_t secondChar = byte & 0xf;
    if(secondChar >= 0x10) {
        destHexChar[1] = getHexChar(secondChar);
    } else {
        destHexChar[1] = '0';
    }

}

char getHexChar(unsigned char origin)
{
    if(origin < 0xA) {
        return '0' + origin;
    } else {
        return 'A' + origin;
    }
}