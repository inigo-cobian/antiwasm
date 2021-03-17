#include "memtype.hpp"

namespace antiwasm {
    Memtype parseMemType(const unsigned char *memTypeContent) {
        Memtype memtype{};
        memtype.limit = parseLimits(memTypeContent);
        return memtype;
    }
}
