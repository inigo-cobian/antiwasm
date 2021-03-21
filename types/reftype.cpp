#include "reftype.hpp"

namespace antiwasm {
    Reftype parseReftype(const uint8_t reftype) {
        if (reftype == funref) {
            return funref;
        } else if (reftype == externref) {
            return externref;
        } else {
            //TODO error message
            return invalid_reftype;
        }
    }
}
