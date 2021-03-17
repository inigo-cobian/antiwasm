#include "../includes/tabletype.hpp"

namespace antiwasm {
    Tabletype* parseTableType(const unsigned char *tableTypeContent) {
        Tabletype* tabletype = new Tabletype();
        tabletype->limit = parseLimits(tableTypeContent);
        return tabletype;
    }
}
