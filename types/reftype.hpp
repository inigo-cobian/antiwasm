#ifndef ANTIWASM_REFTYPE_HPP
#define ANTIWASM_REFTYPE_HPP

#include <cstdint>

const auto REFTYPE_SIZE = 1;

enum Reftype : uint32_t {
    funref = 0x70,
    externref = 0x6F
};

namespace antiwasm {
    /**
     * Parses and returns the reftype value.
     * @param reftype
     * @return
     */
    Reftype parseReftype(const unsigned char reftype);
}

#endif //ANTIWASM_REFTYPE_HPP