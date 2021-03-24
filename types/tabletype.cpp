#include "tabletype.hpp"

namespace antiwasm {
    Tabletype parseTableType(const uint8_t *tableTypeContent) {
        Tabletype tabletype{};
        tabletype.reftype = parseReftype(tableTypeContent[0]);
        if (tabletype.reftype == invalid_reftype) {
            tabletype.error = true;
            return tabletype;
        }
        tabletype.limit = parseLimits(&tableTypeContent[1]);
        if (tabletype.limit.error) {
            tabletype.error = true;
        }
        return tabletype;
    }
}
