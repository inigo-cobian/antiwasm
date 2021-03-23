#ifndef ANTIWASM_RESULTTYPE_HPP
#define ANTIWASM_RESULTTYPE_HPP

#include <vector>
#include "valtype.hpp"

struct Resulttype {
    std::vector<Valtype> valtypeVector;
    bool error = false;
};

const auto BYTES_VALTYPE_HEADER = 1; //TODO ¿general vec size?

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
