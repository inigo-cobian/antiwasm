#ifndef ANTIWASM_MEMTYPE_HPP
#define ANTIWASM_MEMTYPE_HPP

#include "limits.hpp"

union Memtype {
    Limit* limit;
};

namespace antiwasm {
    Memtype parseMemType(const unsigned char *memTypeContent);
}

#endif //ANTIWASM_MEMTYPE_HPP
