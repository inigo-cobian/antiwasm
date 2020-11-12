#include "types_parser.hpp"

namespace antiwasm {
    static const unsigned char i32 = 0x7F;
    static const unsigned char i64 = 0x7E;
    static const unsigned char f32 = 0x7D;
    static const unsigned char f64 = 0x7C;

    void parseFuncTypeVec(unsigned char* funcTypeVecSection)
    {
        int pointer = 1;
        int numberOfFuncTypes = funcTypeVecSection[0];
        std::cout << "Number of func types at section: " << numberOfFuncTypes << std::endl;

        for(int i = 0; i < numberOfFuncTypes; i++) {
            parseFuncType(funcTypeVecSection, pointer);
        }
    }

    void parseFuncType(unsigned char* funcTypeSection, int &pointer)
    {
        if(funcTypeSection[pointer++] != 0x60)
        {
            std::cout << "Not a function type, but a " << (int)funcTypeSection[pointer] << " at " << (int)pointer << std::endl;
            return;
        }

        // Parse the first result type of the function type
        parseResultType(funcTypeSection, pointer);

        // Parse the second result type of the function type
        parseResultType(funcTypeSection, pointer);

    }

    void parseResultType(unsigned char* resultTypeSection, int &pointer)
    {
        unsigned char sizeOfResultType = resultTypeSection[pointer++];

        if(sizeOfResultType == 0x00) {
        }
        else if(sizeOfResultType == 0x01) {
            parseValType(resultTypeSection[pointer]);
            pointer++;
        }
    }

    void parseValType(unsigned char valType)
    {
        if(valType == i32)
            std::cout << "i32" << std::endl;
        else if(valType == i64)
            std::cout << "i64" << std::endl;
        else if(valType == f32)
            std::cout << "f32" << std::endl;
        else if(valType == f64)
            std::cout << "f64" << std::endl;
    }
}
