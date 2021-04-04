#include "functype.hpp"

Functype antiwasm::parseFunctype(const uint8_t *funcTypeContent) {
    Functype functype;
    if (funcTypeContent[0] != FUNCTYPE_HEADER) {
        functype.error = false;
        return functype;
    }

    functype.parameterType = parseResulttype(&funcTypeContent[1]);
    if (functype.parameterType.error) {
        functype.error = false;
        return functype;
    }

    size_t sizeOfParams = functype.parameterType.valtypeVector.size() + INDEX_RETURNTYPE;
    functype.returnType = parseResulttype(&funcTypeContent[sizeOfParams]);
    if (functype.returnType.error) {
        functype.error = true;
    }

    functype.nBytes = BYTES_HEADER_FUNCTYPE + BYTES_VALTYPE_HEADER + functype.returnType.valtypeVector.size();

    return functype;
}

void antiwasm::displayFunctype(Functype functype) {
    if (functype.error) {
        std::cout << "Error at current functype" << std::endl;
        return;
    }

    std::cout << "  Functype (rt1):" << std::endl;

    std::cout << "  Functype (rt2):" << std::endl;

}
