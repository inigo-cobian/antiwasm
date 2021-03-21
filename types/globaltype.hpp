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
    Globaltype parseGlobaltype(const unsigned char *globaltypeContent);
}

#endif //ANTIWASM_GLOBALTYPE_HPP
