#include "valtype.hpp"

namespace antiwasm {
    Valtype parseValtype(const unsigned char valtypeContent) {
        if(valtypeContent <= i32 && valtypeContent >= f64) {
            parseNumType(valtypeContent);
        } else if (valtypeContent == funref || valtypeContent == externref) {
            parseReftype(valtypeContent);
        }
    }
}
