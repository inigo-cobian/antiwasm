#include "../includes/memtype.hpp"

namespace antiwasm {
    int parseMemType(const unsigned char *memType) {
        parseLimits(memType);
    }
}
