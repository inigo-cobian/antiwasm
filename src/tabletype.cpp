#include "../includes/tabletype.hpp"

namespace antiwasm {
    Tabletype* parseTableType(const unsigned char *tableTypeContent) {
        Tabletype* tabletype = new Tabletype();
        tabletype->reftype = parseReftype(tableTypeContent[0]);
        tabletype->limit = parseLimits(tableTypeContent);
        return tabletype;
    }
}
