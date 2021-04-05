#include "tabletype.hpp"

namespace antiwasm {
    Tabletype parseTableType(const uint8_t *tableTypeContent) {
        Tabletype tabletype{};
        tabletype.reftype = parseReftype(tableTypeContent[0]);
        if (tabletype.reftype == invalid_reftype) {
            std::cout << "Error at reftype" << std::endl;
            tabletype.error = true;
            return tabletype;
        }
        tabletype.limit = parseLimits(&tableTypeContent[1]);
        if (tabletype.limit.error) {
            std::cout << "Error at limit" << std::endl;
            tabletype.error = true;
        }
        return tabletype;
    }

    void displayTabletype(Tabletype tabletype) {
        if (tabletype.error) {
            std::cout << "Error at tabletype" << std::endl;
            //TODO error
        }
        std::cout << "    [";
        displayReftype(tabletype.reftype);
        std::cout << "] ";
        displayLimits(tabletype.limit);
        std::cout << std::endl;
    }
}
