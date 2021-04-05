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

    void displayReftype(Reftype reftype) {
        switch (reftype) {
            case funref:
                std::cout << "funref";
                break;
            case externref:
                std::cout << "externref";
                break;
            case invalid_reftype:
                std::cout << "error.reftype";
                break;
        }
    }
}
