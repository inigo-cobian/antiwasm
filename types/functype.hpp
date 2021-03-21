#ifndef ANTIWASM_FUNCTYPE_HPP
#define ANTIWASM_FUNCTYPE_HPP

#include "resulttype.hpp"

const uint32_t FUNCTYPE_HEADER = 0x60;

struct Functype {
    Resulttype parameterType;
    Resulttype returnType; //TODO check if this name has the same meaning in the docs
    bool error = false;
};

namespace antiwasm {
    /**
     * Parses and generates the parsed functype.
     * Adds error if cannot complete the parsing.
     * @param funcTypeContent
     * @return
     */
    Functype parseFunctype(const unsigned char *funcTypeContent);
}

#endif //ANTIWASM_FUNCTYPE_HPP
