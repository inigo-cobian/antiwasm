#ifndef ANTIWASM_REFTYPE_HPP
#define ANTIWASM_REFTYPE_HPP

#include <cstdint>

enum reftypes : uint32_t {
    funref = 0x70,
    externref = 0x6F
};


#endif //ANTIWASM_REFTYPE_HPP
