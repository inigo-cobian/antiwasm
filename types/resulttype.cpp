#include "resulttype.hpp"

namespace antiwasm {
    Resulttype parseResulttype(const uint8_t *resultTypeContent) {
        Resulttype resulttype;
        auto elementsInResulttype = resultTypeContent[0];
        auto pointer = 1;
        for (auto i = 0; i < elementsInResulttype; i++) {
            auto elementType = resultTypeContent[pointer];
            Valtype valtype = parseValtype(elementType);
            resulttype.valtypeVector.push_back(valtype);
            if (valtype.error) {
                resulttype.error = true;
                return resulttype;
            }
            pointer++;
        }
        return resulttype;
    }
}
