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
        int numberOfTypesAtSection = typeSectionBuffer[0];
        std::cout << "Number of types at section: " << numberOfTypesAtSection << std::endl;

        for(int i = 0; i < numberOfTypesAtSection; i++) {
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
        return nullptr;
    }

    unsigned char* parseFunctionSection(unsigned char sizeOfSection)
    {
        unsigned char* functionSectionBuffer = getSection(sizeOfSection);
        unsigned char* vectorBuffer;

        int pointer = 1;
        int numberOfFunctionsAtSection = functionSectionBuffer[0];
        std::cout << "Number of functions at section: " << numberOfFunctionsAtSection << std::endl;

        //TODO

        free(functionSectionBuffer);
        return driver->GetNextBytes(2);
    }

    unsigned char* parseTableSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseMemorySection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseGlobalSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseExportSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseStartSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseElementSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseCodeSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    unsigned char* parseDataSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }

    /* Gets the whole section */
    unsigned char* getSection(unsigned char sizeOfSection)
    {
        unsigned char* sectionBuffer = (unsigned char*)malloc(sizeof(unsigned char) * sizeOfSection);
        return driver->GetNextBytes(sizeOfSection);
    }
}
