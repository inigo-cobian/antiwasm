#ifndef ANTIWASM_RESULTTYPE_HPP
#define ANTIWASM_RESULTTYPE_HPP

#include <vector>

struct Resulttype {
    Vector<Valtype> valtypeVector;
};

namespace antiwasm {
    Resulttype parseResulttype(const unsigned char *resultTypeContent);
}


#endif //ANTIWASM_RESULTTYPE_HPP
