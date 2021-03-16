#ifndef ANTIWASM_TABLETYPE_HPP
#define ANTIWASM_TABLETYPE_HPP

#include "limits.hpp"
#include "reftype.hpp"

struct Tabletype {
    Reftype reftype;
    Limit* limit;
};

namespace antiwasm {//TODO change
    Memtype* parseMemType(const unsigned char *memTypeContent);
}

#endif //ANTIWASM_TABLETYPE_HPP
