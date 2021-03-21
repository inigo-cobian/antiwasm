#ifndef ANTIWASM_GLOBALTYPE_HPP
#define ANTIWASM_GLOBALTYPE_HPP

#include "valtype.hpp"
#include "mut.hpp"

struct Globaltype {
    Valtype valtype;
    Mut mut;
    bool error = false;
};

namespace antiwasm {
    /**
     * Parses and generates the parsed globaltype.
     * Adds error if cannot complete the parsing.
     * @param globaltypeContent
     * @return
     */
    Globaltype parseGlobaltype(const unsigned char *globaltypeContent);
}

#endif //ANTIWASM_GLOBALTYPE_HPP
