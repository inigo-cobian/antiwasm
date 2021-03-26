#include "leb128.hpp"

int32_t antiwasm::transformLeb128ToSignedInt32(uint8_t *leb128) {
    return 0; // TODO
}

int64_t antiwasm::transformLeb128ToSignedInt64(uint8_t *leb128) {
    return 0; // TODO
}

uint32_t antiwasm::transformLeb128ToUnsignedInt32(uint8_t *leb128) {
    uint32_t result = 0;
    int shift = 0;
    int pos = 0;
    while (true) {
        uint8_t currentByte = leb128[pos];
        result |= (currentByte & 0b0111'1111) << shift;
        if ((currentByte & 1000'0000) == 0) {
            break;
        }
        shift += 7;
        pos++;
    }

    return result;

    /*
    int pos = 0;
    uint32_t decodedValue = 0;
    int shift = 0;
    do {
        uint32_t currentShift = (leb128[pos] & 0b0111'1111);
        std::cout << "AAA: " << std::hex << currentShift << std::endl;
        std::cout << "pre: " << std::hex << decodedValue << std::endl;
        decodedValue <<= 7;
        std::cout << "pos: " << std::hex << decodedValue << std::endl;
        decodedValue |= currentShift;
        std::cout << "BBB: " << std::hex << decodedValue << std::endl;
        std::cout << "CCC: " << std::hex << (decodedValue >> 7) << std::endl;


        if ((leb128[pos] & 1000'0000) == 0) {
            std::cout << "XXX: " << std::hex << (decodedValue) << std::endl;
            std::cout << "YYY: " << std::dec << decodedValue << std::endl;
            return decodedValue;
        }

        pos++;
    } while (true);

    return decodedValue;
    */
}

uint64_t antiwasm::transformLeb128ToUnsignedInt64(uint8_t *leb128) {
    return 0; // TODO
}

int antiwasm::sizeOfLeb128(uint8_t *leb128) {
    int size = 0;
    while (leb128[size++] & 0b1000'0000);
    return size;
}
