#include "leb128.hpp"

int32_t antiwasm::transformLeb128ToSignedInt32(const uint8_t *leb128) {
    return 0; // TODO
}

int64_t antiwasm::transformLeb128ToSignedInt64(const uint8_t *leb128) {
    return 0; // TODO
}

uint32_t antiwasm::transformLeb128ToUnsignedInt32(const uint8_t *leb128) {
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
}

uint64_t antiwasm::transformLeb128ToUnsignedInt64(const uint8_t *leb128) {
    uint64_t result = 0;
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
}

int antiwasm::sizeOfLeb128(const uint8_t *leb128) {
    int size = 0;
    while (leb128[size++] & 0b1000'0000);
    BOOST_LOG_TRIVIAL(info) << "[leb128] Returning size of LEB128: " << size;
    return size;
}
