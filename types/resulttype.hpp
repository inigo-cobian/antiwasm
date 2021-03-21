#ifndef ANTIWASM_RESULTTYPE_HPP
#define ANTIWASM_RESULTTYPE_HPP

#include <vector>
#include "valtype.hpp"

struct Resulttype {
    std::vector<Valtype> valtypeVector;
    bool error = false;
};

namespace antiwasm {
    /**
     * Parses and generates the parsed resulttype.
     * Adds error if cannot complete the parsing.
     * @param resultTypeContent
     * @return
     */
    Resulttype parseResulttype(const unsigned char *resultTypeContent);
}


#endif //ANTIWASM_RESULTTYPE_HPP
