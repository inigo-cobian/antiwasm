#ifndef ANTIWASM_RESULTTYPE_HPP
#define ANTIWASM_RESULTTYPE_HPP

#include <vector>
#include "valtype.hpp"

struct Resulttype {
    std::vector<Valtype> valtypeVector;
    bool error = false;
};

namespace antiwasm {
    Resulttype parseResulttype(const unsigned char *resultTypeContent);
}


#endif //ANTIWASM_RESULTTYPE_HPP
