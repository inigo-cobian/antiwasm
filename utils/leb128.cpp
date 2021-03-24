#include "leb128.hpp"

int32_t antiwasm::transformLeb128ToSignedInt32(uint8_t *leb128)
{
    return 0; // TODO
}

int64_t antiwasm::transformLeb128ToSignedInt64(uint8_t *leb128)
{
    return 0; // TODO
}

uint32_t antiwasm::transformLeb128ToUnsignedInt32(uint8_t *leb128)
{
    int pos = 0;
    uint32_t decodedValue = 0;
    int shifts = 0;
    do {
        auto currentShift = (leb128[pos] & 0b0111'1111);
        decodedValue <<= shifts;
        decodedValue |= currentShift;

        if(!(leb128[pos] & 1000'0000) ) {
            break;
        }

        shifts += 7;
        pos++;
    } while(true);

    return decodedValue; // TODO
}

uint64_t antiwasm::transformLeb128ToUnsignedInt64(uint8_t *leb128)
{
    return 0; // TODO
}

int antiwasm::sizeOfLeb128(uint8_t *leb128)
{
    int size = 0;
    while(leb128[size++] & 0b1000'0000);
    return size;
}
