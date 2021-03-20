#include "resulttype.hpp"

namespace antiwasm {
    Resulttype parseResulttype(const unsigned char *resultTypeContent) {
        Resulttype resulttype;
        auto elementsInResulttype = resultTypeContent[0];
        auto pointer = 1;
        for(auto i = 0; i < elementsInResulttype; i++) {
            auto elementType = resultTypeContent[pointer];
            Valtype valtype = parseValtype(elementType);
            // if(valtype.error) TODO
            resulttype.valtypeVector.push_back(valtype);
            pointer++;
        } //TODO error case
        return resulttype;
    }
}
