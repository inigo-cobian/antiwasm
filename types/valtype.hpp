#ifndef ANTIWASM_VALTYPE_HPP
#define ANTIWASM_VALTYPE_HPP

#include "numtype.hpp"
#include "reftype.hpp"

struct Valtype {
    Numtype numtype; //TODO explain in the docs that they are two elements to keep the code Æ s t h e t i c
    Reftype reftype;
    bool error = false;
};

namespace antiwasm {
    /**
     * Gets a byte and returns the equivalent Valtype
     * @param valtypeContent
     * @return
     */
    Valtype parseValtype(const unsigned char valtypeContent);
}

#endif //ANTIWASM_VALTYPE_HPP
