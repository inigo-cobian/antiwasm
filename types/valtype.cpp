#include "valtype.hpp"

namespace antiwasm {
    Valtype parseValtype(const uint8_t valtypeContent) {
        Valtype valtype;
        if (valtypeContent <= i32 && valtypeContent >= f64) {
            valtype.numtype = parseNumType(valtypeContent);
        } else if (valtypeContent == funref || valtypeContent == externref) {
            valtype.reftype = parseReftype(valtypeContent);
        } else {
            valtype.error = true;
        }
        return valtype;
    }
}
