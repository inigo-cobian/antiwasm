#ifndef ANTIWASM_FUNCTYPE_HPP
#define ANTIWASM_FUNCTYPE_HPP

#include "resulttype.hpp"

struct Functype {
    Resulttype parameterType;
    Resulttype resultType;
};

namespace antiwasm {
    Functype parseFunctype(const unsigned char *funcTypeContent);
}

#endif //ANTIWASM_FUNCTYPE_HPP
