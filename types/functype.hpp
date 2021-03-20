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
    Functype parseFunctype(const unsigned char *funcTypeContent);
}

#endif //ANTIWASM_FUNCTYPE_HPP
