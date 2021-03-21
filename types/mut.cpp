#include "globaltype.hpp"

namespace antiwasm {
    Mut parseMut(const unsigned char mutContent) {
        if(mutContent == Mut::const_) {
            return Mut::const_;
        } else if(mutContent == Mut::var_) {
            return Mut::var_;
        } else {
            return Mut::invalid_mut;
        }
    }
}
