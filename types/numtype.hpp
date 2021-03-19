#ifndef ANTIWASM_NUMTYPE_HPP
#define ANTIWASM_NUMTYPE_HPP

#include <cstdint>

enum Numtype : int32_t {
    i32 = 0x7F,
    i64 = 0x7E,
    f32 = 0x7D,
    f64 = 0x7C,
    invalid = 0xFF
};

namespace antiwasm {
    /**
     * Gets a byte and returns the equivalent NumType
     * @param numtypeContent
     * @return
     */
    Numtype parseNumType(const unsigned char numtypeContent);
}

#endif //ANTIWASM_NUMTYPE_HPP
