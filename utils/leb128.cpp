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
    return 0; // TODO
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
