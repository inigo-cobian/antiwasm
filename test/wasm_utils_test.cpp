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
    correctChars[0] = '0'; correctChars[1] = '2';
    correctChars[2] = 'C'; correctChars[3] = '8';

    auto* outgoingHexChars = bytesToHexChar(incomingBytes, 2);

    BOOST_CHECK_EQUAL(outgoingHexChars[0] , correctChars[0]);
}

BOOST_AUTO_TEST_CASE(getHexChar_getsChar)
{
    uint8_t incomingByte = 0x2;

    char hexChar = getHexChar(incomingByte);

    BOOST_CHECK_EQUAL(hexChar, '2');
}
