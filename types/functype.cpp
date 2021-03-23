#include "functype.hpp"

Functype antiwasm::parseFunctype(const uint8_t *funcTypeContent) {
    Functype functype;
    if(funcTypeContent[0] != FUNCTYPE_HEADER) {
        functype.error = true;
        return functype;
    }

    functype.parameterType = parseResulttype(&funcTypeContent[1]);
    if (functype.parameterType.error) {
        functype.error = true;
        return functype;
    }

    size_t sizeOfParams = functype.parameterType.valtypeVector.size() + INDEX_RETURNTYPE;
    functype.returnType = parseResulttype(&funcTypeContent[sizeOfParams]);
    if (functype.returnType.error) {
        functype.error = true;
    }

    return functype;
}
