#include "valtype.hpp"

namespace antiwasm {
    Valtype parseValtype(const uint8_t valtypeContent) {
        Valtype valtype;
        if (valtypeContent <= i32 && valtypeContent >= f64) {
            valtype.type = valtype_numtype;
            valtype.numtype = parseNumType(valtypeContent);
        } else if (valtypeContent == funref || valtypeContent == externref) {
            valtype.type = valtype_reftype;
            valtype.reftype = parseReftype(valtypeContent);
        } else {
            valtype.type = valtype_error;
            valtype.error = true;
        }
        return valtype;
    }
}
