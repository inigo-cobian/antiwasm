#include "../includes/reftype.hpp"

namespace antiwasm {
    Reftype parseReftype(const unsigned char reftype) {
        if (reftype == funref) {
            return funref;
        } else if (reftype == externref) {
            return externref;
        } else { //TODO error
            return funref;
        }
    }
}
