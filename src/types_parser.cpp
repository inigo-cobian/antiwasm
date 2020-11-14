#include "types_parser.hpp"

namespace antiwasm {
    static const unsigned char i32 = 0x7F;
    static const unsigned char i64 = 0x7E;
    static const unsigned char f32 = 0x7D;
    static const unsigned char f64 = 0x7C;

    static const unsigned char CONST = 0x00;
    static const unsigned char VAR   = 0x01;

    void parseFuncTypeVec(unsigned char* funcTypeVecSection)
    {
        int nFuncTypes = funcTypeVecSection[0];
        int pointer = 1;
        std::cout << "Number of func types at section: " << nFuncTypes << std::endl;

        for(int i = 0; i < nFuncTypes; i++) {
            parseFuncType(funcTypeVecSection, pointer);
        }
    }

    void parseFuncType(unsigned char* funcTypeSection, int &pointer)
    {
        if(funcTypeSection[pointer] != 0x60)
        {
            std::cout << "Not a function type, but a " << (int)funcTypeSection[pointer] << " at " << (int)pointer << std::endl;
            return;
        }
        pointer++;

        // Parse the first result type of the function type
        parseResultType(funcTypeSection, pointer);

        // Parse the second result type of the function type
        parseResultType(funcTypeSection, pointer);

    }

    void parseResultType(unsigned char* resultTypeSection, int &pointer)
    {
        int nFuncTypes = resultTypeSection[pointer];
        pointer++;
        for(int i = 0; i < nFuncTypes; i++) {
            parseValType(resultTypeSection[pointer]);
            pointer++;
        }
    }

    void parseValType(unsigned char valType)
    {
        if(valType == i32) {
            //TODO
            std::cout << "i32" << std::endl;
        }
        else if(valType == i64) {
            //TODO
            std::cout << "i64" << std::endl;
        }
        else if(valType == f32) {
            //TODO
            std::cout << "f32" << std::endl;
        }
        else if(valType == f64) {
            //TODO
            std::cout << "f64" << std::endl;
        }
        else printf("Unknown value: %0x\n", valType);
    }

    void parseMut(unsigned char mut)
    {
            if(mut == CONST) {
                //TODO
                std::cout << "const" << std::endl;
            }
            else if(mut == VAR) {
                //TODO
                std::cout << "var" << std::endl;
            }
            else printf("Unknown mut: %0x\n", mut);
    }

    void parseGlobalVec(unsigned char *globalSectionBuffer)
    {
        int nGlobals = globalSectionBuffer[0];
        int pointer = 1;
        std::cout << "Number of globals at section: " << nGlobals << std::endl;

        for(int i = 0; i < nGlobals; i++) {
            parseValType(globalSectionBuffer[pointer++]);
            parseMut(globalSectionBuffer[pointer++]);
            parseInstr(globalSectionBuffer, pointer);
        }
    }

    void parseInstr(unsigned char *instruction, int &pointer)
    {
        //TODO create the parsing of instructions
        do {
            if(instruction[pointer++] == 0x0B) {
                std::cout << "END" << std::endl;
                return;
            }
        }while(true);
    }

}
