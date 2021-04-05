#include "memtype.hpp"

namespace antiwasm {
    Memtype parseMemType(const uint8_t *memTypeContent) {
        Memtype memtype{};
        memtype.limit = parseLimits(memTypeContent);
        return memtype;
    }

    void displayMemtype(Memtype memtype) {
        if(memtype.limit.type == limit_min) {
            std::cout << "  memtype: [" << memtype.limit.min << "-MAX]" << std::endl;
        } else if(memtype.limit.type == limit_min_max) {
            std::cout << "  memtype: [" << memtype.limit.min << "-"
                      << memtype.limit.max << "]" << std::endl;
        } else {
            std::cout << "  Error at current memtype" << std::endl;
        }
    }
}
