#include "../includes/types_parser.hpp"

namespace antiwasm {
    static const unsigned char CONST = 0x00;
    static const unsigned char VAR = 0x01;

    void parseFuncTypeVec(unsigned char *funcTypeVecSection) {
        int nFuncTypes = funcTypeVecSection[0];
        int pointer = 1;
        BOOST_LOG_TRIVIAL(debug) << "[types_parser] Number of func types at section: " << nFuncTypes;

        for (int i = 0; i < nFuncTypes; i++) {
            parseFuncType(funcTypeVecSection, pointer);
        }
    }

    void parseFuncType(unsigned char *funcTypeSection, int &pointer) {
        if (funcTypeSection[pointer] != 0x60) {
            BOOST_LOG_TRIVIAL(error) << "[types_parser] Not a function type. Val " << (int) funcTypeSection[pointer]
                                     << " at " << (int) pointer;
            return;
        }
        pointer++;

        // Parse the first result type of the function type
        parseResultType(funcTypeSection, pointer);

        // Parse the second result type of the function type
        parseResultType(funcTypeSection, pointer);

    }

    void parseResultType(unsigned char *resultTypeSection, int &pointer) {
        int nFuncTypes = resultTypeSection[pointer];
        pointer++;
        for (int i = 0; i < nFuncTypes; i++) {
            parseValType(resultTypeSection[pointer]);
            pointer++;
        }
    }

    void parseValType(unsigned char valType) {
        if (valType == i32) {
            BOOST_LOG_TRIVIAL(trace) << "[types_parser] i32";
        } else if (valType == i64) {
            BOOST_LOG_TRIVIAL(trace) << "[types_parser] i64";
        } else if (valType == f32) {
            BOOST_LOG_TRIVIAL(trace) << "[types_parser] f32";
        } else if (valType == f64) {
            BOOST_LOG_TRIVIAL(trace) << "[types_parser] f64";
        } else {
            BOOST_LOG_TRIVIAL(error) << "[types_parser] Unknown value: " << valType; //TODO print as a hex
        }
    }

    void parseMut(unsigned char mut) {
        if (mut == CONST) {
            BOOST_LOG_TRIVIAL(trace) << "[types_parser] const";
        } else if (mut == VAR) {
            BOOST_LOG_TRIVIAL(trace) << "[types_parser] var";
        } else {
            BOOST_LOG_TRIVIAL(error) << "[types_parser] Unknown mut: " << mut; //TODO print as a hex
        }
    }

    void parseGlobalVec(unsigned char *globalSectionBuffer) {
        int nGlobals = globalSectionBuffer[0];
        int pointer = 1;
        BOOST_LOG_TRIVIAL(debug) << "[types_parser] Number of globals at section: " << nGlobals;

        for (int i = 0; i < nGlobals; i++) {
            parseValType(globalSectionBuffer[pointer++]);
            parseMut(globalSectionBuffer[pointer++]);
            //parseInstr(globalSectionBuffer, pointer);
        }
    }

    void parseElementVec(unsigned char *elementVec) {
        int nElements = elementVec[0];
        int pointer = 1;
        BOOST_LOG_TRIVIAL(debug) << "[types_parser] Number of elements at section: " << nElements;

        for (int i = 0; i < nElements; i++) {
            //Check the tableidx
            //At version 1.0 only the value 0x00 is valid
            if (elementVec[pointer++] != 0x00) {
                //TODO warning message
            }

            //Get the offset as an expression
            //parseInstr(elementVec, pointer);

            parseFuncIdxVec(elementVec, pointer);
        }
    }

    void parseFuncIdxVec(unsigned char *funcIdxVec, int &pointer) {
        int nFuncIdx = funcIdxVec[pointer++];

        for (int i = 0; i < nFuncIdx; i++) {
            BOOST_LOG_TRIVIAL(debug) << "[types_parser] funcIdx: 0x" << std::hex << (int) funcIdxVec[pointer++];
        }
    }

    void parseDataVec(unsigned char *dataVec) {
        int nDatas = dataVec[0];
        int pointer = 1;
        BOOST_LOG_TRIVIAL(debug) << "[types_parser] Number of datas at section: " << nDatas;

        for (int i = 0; i < nDatas; i++) {
            //Check the memidx
            //At version 1.0 only the value 0x00 is valid
            if (dataVec[pointer++] != 0x00) {
                //TODO warning message
            }

            //Get the offset as an expression
            //parseInstr(dataVec, pointer);

            parseByteVec(dataVec, pointer);
        }
    }

    void parseByteVec(const unsigned char *byteVec, int pointer) {
        int nBytes = byteVec[pointer++];
        for (int i = 0; i < nBytes; i++) {
            pointer++;
            //TODO
        }
    }

    void parseImportVec(unsigned char *importVec) {
        int nImports = importVec[0];
        int pointer = 1;
        BOOST_LOG_TRIVIAL(debug) << "[types_parser] Number of imports at section: " << nImports;

        for (int i = 0; i < nImports; i++) {
            //Get the first instance name (module)
            parseName((char *) importVec, pointer);

            //Get the second instance name (name)
            parseName((char *) importVec, pointer);

            parseImportDesc(importVec, pointer);
        }
    }

    void parseName(char *nameSectionBuffer, int &pointer) {
        auto nBytesAtName = nameSectionBuffer[pointer++];
        char *nameBuffer = (char *) malloc(sizeof(char) * nBytesAtName);

        std::memcpy(nameBuffer, &nameSectionBuffer[pointer], nBytesAtName); //+1 so \0 can be added
        nameBuffer[nBytesAtName] = '\0';

        pointer += nBytesAtName;

        std::string name = std::string(nameBuffer);
        BOOST_LOG_TRIVIAL(debug) << "[types_parser] Name: " << name;
    }

    void parseImportDesc(unsigned char *importDesc, int &pointer) {
        //FIXME For now just ignore the following two bytes. See importdesc
        pointer += 2;
    }

    void parseExportVec(unsigned char *exportVec) {
        int nExports = exportVec[0];
        int pointer = 1;
        BOOST_LOG_TRIVIAL(debug) << "[types_parser] Number of exports at section: " << nExports;

        for (int i = 0; i < nExports; i++) {
            //Get the name of the exported item
            parseName((char *) exportVec, pointer);

            parseExportDesc(exportVec, pointer);
        }
    }

    void parseExportDesc(unsigned char *exportDesc, int &pointer) {
        //FIXME For now just ignore the following two bytes. See exportDesc
        pointer += 2;
    }

    void parseStart(unsigned char startFunc) {
        //TODO get start func
    }
}
