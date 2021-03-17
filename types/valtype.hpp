#ifndef ANTIWASM_VALTYPE_HPP
#define ANTIWASM_VALTYPE_HPP

#include "numtype.hpp"
#include "reftype.hpp"

union Valtype {
    Numtype numtype;
    Reftype reftype;
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
