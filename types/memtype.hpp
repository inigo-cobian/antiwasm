#ifndef ANTIWASM_MEMTYPE_HPP
#define ANTIWASM_MEMTYPE_HPP

#include "limits.hpp"

union Memtype {
    Limit limit;
};

namespace antiwasm {
    /**
     * Parses and generates the parsed memtype.
     * Adds error if cannot complete the parsing.
     * @param memTypeContent
     * @return
     */
    Memtype parseMemType(const uint8_t *memTypeContent);
}

#endif //ANTIWASM_MEMTYPE_HPP
