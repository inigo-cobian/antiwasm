#include "numtype.hpp"

namespace antiwasm {
    Numtype parseNumType(const unsigned char numtypeContent) {
        if(numtypeContent == i32) {
            return i32;
        } else if(numtypeContent == i64) {
            return i64;
        } else if(numtypeContent == f32) {
            return f32;
        } else if(numtypeContent == f64) {
            return f64;
        } else {
            //TODO error message
            return invalid_numtype;
        }
    }
}
