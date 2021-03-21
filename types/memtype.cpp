#include "memtype.hpp"

namespace antiwasm {
    Memtype parseMemType(const uint8_t *memTypeContent) {
        Memtype memtype{};
        memtype.limit = parseLimits(memTypeContent);
        return memtype;
    }
}
