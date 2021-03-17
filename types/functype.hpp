#ifndef ANTIWASM_FUNCTYPE_HPP
#define ANTIWASM_FUNCTYPE_HPP

#include "resulttype.hpp"

struct Functype {
    Resulttype parameterType;
    Resulttype resultType;
};

namespace antiwasm {
    Resulttype parseFunctype(const unsigned char *resultTypeContent);
}

#endif //ANTIWASM_FUNCTYPE_HPP
