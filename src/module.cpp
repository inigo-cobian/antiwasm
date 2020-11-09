#include "module.hpp"

namespace antiwasm {

    Driver *driver;

    //TODO create parsers for the different sections
    size_t parseSections(unsigned char* buffer) { //Size of the buffer -> 2
        driver = driver->GetInstance();
        if(buffer[0] == Section::Custom) {
            std::cout << "Custom Section" << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseCustomSection(sectionSize);
        }
        if(buffer[0] == Section::Type) {
            std::cout << "Type Section of size " << (unsigned int)buffer[1] << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseTypeSection(sectionSize);
        }
        if(buffer[0] == Section::Import) {
            std::cout << "Import Section of size " << (unsigned int)buffer[1] << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseImportSection(sectionSize);
        }
        if(buffer[0] == Section::Function) {
            std::cout << "Function Section of size " << (unsigned int)buffer[1] << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseFunctionSection(sectionSize);
        }
        if(buffer[0] == Section::Table) {
            std::cout << "Table Section of size " << (unsigned int)buffer[1] << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseTableSection(sectionSize);
        }
        if(buffer[0] == Section::Memory) {
            std::cout << "Memory Section of size " << (unsigned int)buffer[1] << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseMemorySection(sectionSize);
        }
        if(buffer[0] == Section::Global) {
            std::cout << "Global Section of size " << (unsigned int)buffer[1] << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseGlobalSection(sectionSize);
        }
        if(buffer[0] == Section::Export) {
            std::cout << "Export Section of size " << (unsigned int)buffer[1] << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseExportSection(sectionSize);
        }
        if(buffer[0] == Section::Start) {
            std::cout << "Start Section" << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseStartSection(sectionSize);
        }
        if(buffer[0] == Section::Element) {
            std::cout << "Element Section" << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseElementSection(sectionSize);
        }
        if(buffer[0] == Section::Code) {
            std::cout << "Code Section" << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseCodeSection(sectionSize);
        }
        if(buffer[0] == Section::Data) {
            std::cout << "Data Section" << std::endl;
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseDataSection(sectionSize);
        }
        return 0;
    }

    unsigned char* parseCustomSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }
    
    unsigned char* parseTypeSection(unsigned char sizeOfSection)
    {
        unsigned char* typeSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfTypes = typeSectionBuffer[0];
        std::cout << "Number of types at section: " << numberOfTypes << std::endl;

        for(int i = 0; i < numberOfTypes; i++) {
            if(typeSectionBuffer[pointer] != 0x60) {
                std::cout << "Error. Not a function type" << std::endl;
                exit (-1);
            }
            //TODO
            
        }
        free(typeSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseImportSection(unsigned char sizeOfSection)
    {
        unsigned char* importSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfImports = importSectionBuffer[0];
        std::cout << "Number of imports at section: " << numberOfImports << std::endl;

        //TODO

        free(importSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseFunctionSection(unsigned char sizeOfSection)
    {
        unsigned char* functionSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfFunctions = functionSectionBuffer[0];
        std::cout << "Number of functions at section: " << numberOfFunctions << std::endl;

        //TODO

        free(functionSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseTableSection(unsigned char sizeOfSection)
    {
        unsigned char* tableSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfTables = tableSectionBuffer[0];
        std::cout << "Number of tables at section: " << numberOfTables << std::endl;

        //TODO

        free(tableSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseMemorySection(unsigned char sizeOfSection)
    {
        unsigned char* memorySectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfMemories = memorySectionBuffer[0];
        std::cout << "Number of memories at section: " << numberOfMemories << std::endl;

        //TODO

        free(memorySectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseGlobalSection(unsigned char sizeOfSection)
    {
        unsigned char* globalSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfGlobals = globalSectionBuffer[0];
        std::cout << "Number of globals at section: " << numberOfGlobals << std::endl;

        //TODO

        free(globalSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseExportSection(unsigned char sizeOfSection)
    {
        unsigned char* exportSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfExports = exportSectionBuffer[0];
        std::cout << "Number of exports at section: " << numberOfExports << std::endl;

        //TODO

        free(exportSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseStartSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseElementSection(unsigned char sizeOfSection)
    {
        unsigned char* elementSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfElements = elementSectionBuffer[0];
        std::cout << "Number of elements at section: " << numberOfElements << std::endl;

        //TODO

        free(elementSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseCodeSection(unsigned char sizeOfSection)
    {
        unsigned char* codeSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfCodes = codeSectionBuffer[0];
        std::cout << "Number of codes at section: " << numberOfCodes << std::endl;

        //TODO

        free(codeSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseDataSection(unsigned char sizeOfSection)
    {
        unsigned char* dataSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfDatas = dataSectionBuffer[0];
        std::cout << "Number of data at section: " << numberOfDatas << std::endl;

        //TODO

        free(dataSectionBuffer);
        return driver->GetNextBytes(2);
    }

    /* Gets the whole section */
    unsigned char* getSection(unsigned char sizeOfSection)
    {
        unsigned char* sectionBuffer = (unsigned char*)malloc(sizeof(unsigned char) * sizeOfSection);
        return driver->GetNextBytes(sizeOfSection);
    }
}
