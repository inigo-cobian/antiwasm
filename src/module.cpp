#include "module.hpp"

namespace antiwasm {

    Driver *driver;


    //TODO create parsers for the different sections
    size_t parseSections(unsigned char* buffer) { //Size of the buffer -> 2
        driver = driver->GetInstance();
        if(buffer[0] == Section::Custom) {
            std::cout << "Custom Section" << std::endl;
        }
        else if(buffer[0] == Section::Type) {
            std::cout << "Type Section of size " << (unsigned int)buffer[1] << std::endl;
            parseTypeSection(buffer[1]);
        }
        else if(buffer[0] == Section::Import) {
            std::cout << "Import Section of size " << (unsigned int)buffer[1] << std::endl;
        }
        else if(buffer[0] == Section::Function) {
            std::cout << "Function Section of size " << (unsigned int)buffer[1] << std::endl;
        }
        else if(buffer[0] == Section::Table) {
            std::cout << "Table Section of size " << (unsigned int)buffer[1] << std::endl;
        }
        else if(buffer[0] == Section::Memory) {
            std::cout << "Memory Section of size " << (unsigned int)buffer[1] << std::endl;
        }
        else if(buffer[0] == Section::Global) {
            std::cout << "Global Section of size " << (unsigned int)buffer[1] << std::endl;
        }
        else if(buffer[0] == Section::Export) {
            std::cout << "Export Section of size " << (unsigned int)buffer[1] << std::endl;
        }
        else if(buffer[0] == Section::Start) {
            std::cout << "Start Section" << std::endl;
        }
        else if(buffer[0] == Section::Element) {
            std::cout << "Element Section" << std::endl;
        }
        else if(buffer[0] == Section::Code) {
            std::cout << "Code Section" << std::endl;
        }
        else if(buffer[0] == Section::Data) {
            std::cout << "Data Section" << std::endl;
        }
        return 0;
    }
    
    void parseTypeSection(unsigned char sizeOfSection)
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
        parseSections(driver->GetNextBytes(2));

    }

    /* Gets the whole section */
    unsigned char* getSection(unsigned char sizeOfSection)
    {
        unsigned char* sectionBuffer = (unsigned char*)malloc(sizeof(unsigned char) * sizeOfSection);
        return driver->GetNextBytes(sizeOfSection);
    }
}
