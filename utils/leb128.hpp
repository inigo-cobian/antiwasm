#ifndef ANTIWASM_LEB128_HPP
#define ANTIWASM_LEB128_HPP

#include <cstdint>

namespace antiwasm {
    int32_t transformLeb128ToSignedInt32(uint8_t *leb128);
    int64_t transformLeb128ToSignedInt64(uint8_t *leb128);

    uint32_t transformLeb128ToUnsignedInt32(uint8_t *leb128);
    uint64_t transformLeb128ToUnsignedInt64(uint8_t *leb128);

    int sizeOfLeb128(uint8_t *leb128);
}

#endif //ANTIWASM_LEB128_HPP
