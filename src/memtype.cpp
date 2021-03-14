#include "../includes/memtype.hpp"

namespace antiwasm {
    Memtype* parseMemType(const unsigned char *memTypeContent) {
        Memtype* memtype = new Memtype();
        memtype->limit = parseLimits(memTypeContent);
        return memtype;
    }
}
