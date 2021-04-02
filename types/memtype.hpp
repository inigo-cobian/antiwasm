#ifndef ANTIWASM_MEMTYPE_HPP
#define ANTIWASM_MEMTYPE_HPP

#include "limits.hpp"

struct Memtype {
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

    void displayMemtype(Memtype memtype);
}

#endif //ANTIWASM_MEMTYPE_HPP
