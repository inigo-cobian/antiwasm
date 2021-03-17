#ifndef ANTIWASM_TABLETYPE_HPP
#define ANTIWASM_TABLETYPE_HPP

#include "limits.hpp"
#include "reftype.hpp"

struct Tabletype {
    Reftype reftype;
    Limit limit;
};

namespace antiwasm {
    Tabletype parseTableType(const unsigned char *tableTypeContent);
}

#endif //ANTIWASM_TABLETYPE_HPP
