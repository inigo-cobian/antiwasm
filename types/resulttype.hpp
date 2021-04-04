#ifndef ANTIWASM_RESULTTYPE_HPP
#define ANTIWASM_RESULTTYPE_HPP

#include <vector>
#include "valtype.hpp"
#include "../utils/leb128.hpp"

struct Resulttype {
    std::vector<Valtype> valtypeVector;
    unsigned int nBytes = 0;
    bool error = false;
};

namespace antiwasm {
    /**
     * Parses and generates the parsed resulttype.
     * Adds error if cannot complete the parsing.
     * @param resultTypeContent
     * @return
     */
    Resulttype parseResulttype(const uint8_t *resultTypeContent);
}


#endif //ANTIWASM_RESULTTYPE_HPP
