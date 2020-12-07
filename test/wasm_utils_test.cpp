#define BOOST_TEST_MODULE wasm_util_test
#include <boost/test/included/unit_test.hpp>
#include "../src/wasm_utils.cpp"
#include <cstdint>

BOOST_AUTO_TEST_CASE(bytesToHexChar_correctFormatting)
{
    const int nIncomingBytes = 2;
    uint8_t* incomingBytes = (uint8_t*)malloc(sizeof(uint8_t) * nIncomingBytes);
    incomingBytes[0] = 0x02; incomingBytes[0] = 0xC8;
    char* correctChars = (char*)malloc(sizeof(char) * (nIncomingBytes * 2));
    correctChars[0] = '0'; correctChars[0] = '2'; correctChars[0] = 'C'; correctChars[0] = '8';

    const char* outgoingHexChars = bytesToHexChar(incomingBytes, 2);

    BOOST_CHECK_EQUAL(outgoingHexChars , correctChars);
}