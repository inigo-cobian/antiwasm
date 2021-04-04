#ifndef ANTIWASM_VALTYPE_HPP
#define ANTIWASM_VALTYPE_HPP

#include "numtype.hpp"
#include "reftype.hpp"

enum valtype_type {
    valtype_numtype,
    valtype_reftype,
    valtype_error
};

struct Valtype {
    valtype_type type;
    Numtype numtype; //TODO explain in the docs that they are two elements to keep the code Æ s t h e t i c
    Reftype reftype;
    bool error = false;
};

namespace antiwasm {
    /**
     * Gets a byte and returns the equivalent Valtype.
     * Adds error if cannot complete the parsing.
     * @param valtypeContent
     * @return
     */
    Valtype parseValtype(const uint8_t valtypeContent);
}

#endif //ANTIWASM_VALTYPE_HPP
