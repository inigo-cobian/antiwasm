#include "../includes/module.hpp"

namespace antiwasm {

    std::shared_ptr<Driver> driver;

    //TODO create parsers for the different sections
    size_t parseSections(unsigned char* buffer) { //Size of the buffer -> 2
        driver = Driver::GetInstance();
        if(buffer[0] == SectionId::Custom) {
            BOOST_LOG_TRIVIAL(debug) << "Custom Section";
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseCustomSection(sectionSize);
        }
        if(buffer[0] == SectionId::Type) {
            BOOST_LOG_TRIVIAL(debug) << "Type Section of size " << (unsigned int)buffer[1];
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseTypeSection(sectionSize);
        }
        if(buffer[0] == SectionId::Import) {
            BOOST_LOG_TRIVIAL(debug) << "Import Section of size " << (unsigned int)buffer[1];
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseImportSection(sectionSize);
        }
        if(buffer[0] == SectionId::Function) {
            BOOST_LOG_TRIVIAL(debug) << "Function Section of size " << (unsigned int)buffer[1];
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseFunctionSection(sectionSize);
        }
        if(buffer[0] == SectionId::Table) {
            BOOST_LOG_TRIVIAL(debug) << "Table Section of size " << (unsigned int)buffer[1];
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseTableSection(sectionSize);
        }
        if(buffer[0] == SectionId::Memory) {
            BOOST_LOG_TRIVIAL(debug) << "Memory Section of size " << (unsigned int)buffer[1];
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseMemorySection(sectionSize);
        }
        if(buffer[0] == SectionId::Global) {
            BOOST_LOG_TRIVIAL(debug) << "Global Section of size " << (unsigned int)buffer[1];
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseGlobalSection(sectionSize);
        }
        if(buffer[0] == SectionId::Export) {
            BOOST_LOG_TRIVIAL(debug) << "Export Section of size " << (unsigned int)buffer[1];
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseExportSection(sectionSize);
        }
        if(buffer[0] == SectionId::Start) {
            BOOST_LOG_TRIVIAL(debug) << "Start Section";
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseStartSection(sectionSize);
        }
        if(buffer[0] == SectionId::Element) {
            BOOST_LOG_TRIVIAL(debug) << "Element Section";
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseElementSection(sectionSize);
        }
        if(buffer[0] == SectionId::Code) {
            BOOST_LOG_TRIVIAL(debug) << "Code Section";
            unsigned char sectionSize = buffer[1];
            free(buffer);
            buffer = parseCodeSection(sectionSize);
        }
        if(buffer[0] == SectionId::Data) {
            BOOST_LOG_TRIVIAL(debug) << "Data Section";
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

        parseFuncTypeVec(typeSectionBuffer);

        free(typeSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseImportSection(unsigned char sizeOfSection)
    {
        unsigned char* importSectionBuffer = getSection(sizeOfSection);

        parseImportVec(importSectionBuffer);

        free(importSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseFunctionSection(unsigned char sizeOfSection)
    {
        unsigned char* functionSectionBuffer = getSection(sizeOfSection);

        int pointer = 1;
        int numberOfFunctions = functionSectionBuffer[0];
        BOOST_LOG_TRIVIAL(debug) << "Number of functions at section: " << numberOfFunctions;

        //TODO

        free(functionSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseTableSection(unsigned char sizeOfSection)
    {
        unsigned char* tableSectionBuffer = getSection(sizeOfSection);

        int numberOfTables = tableSectionBuffer[0];
        int pointer = 1; //Pointer for the tableSectionBuffer
        BOOST_LOG_TRIVIAL(debug) << "Number of tables at section: " << numberOfTables;

        int* currentLimits;
        for(int i = 0; i < numberOfTables; i++)
        {
            if(tableSectionBuffer[pointer++] == 0x70)
            {
                pointer += getLimits(&tableSectionBuffer[pointer]);
            }
            else
            {
                BOOST_LOG_TRIVIAL(error) << "Not a table" << std::endl;
                return nullptr;
            }
        }

        free(tableSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseMemorySection(unsigned char sizeOfSection)
    {
        unsigned char* memorySectionBuffer = getSection(sizeOfSection);

        BOOST_LOG_TRIVIAL(debug)  << "Number of memories at section: " << memorySectionBuffer[1];

        //Memory is composed by a limit
        parseLimitVec(memorySectionBuffer);

        free(memorySectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseGlobalSection(unsigned char sizeOfSection)
    {
        unsigned char* globalSectionBuffer = getSection(sizeOfSection);

        parseGlobalVec(globalSectionBuffer);

        free(globalSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseExportSection(unsigned char sizeOfSection)
    {
        unsigned char* exportSectionBuffer = getSection(sizeOfSection);

        parseExportVec(exportSectionBuffer);

        free(exportSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseStartSection(unsigned char sizeOfSection)
    {
        parseStart(sizeOfSection);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseElementSection(unsigned char sizeOfSection)
    {
        unsigned char* elementSectionBuffer = getSection(sizeOfSection);

        parseElementVec(elementSectionBuffer);

        free(elementSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseCodeSection(unsigned char sizeOfSection)
    {
        unsigned char* codeSectionBuffer = getSection(sizeOfSection);

        int pointer = 1;
        int numberOfCodes = codeSectionBuffer[0];
        BOOST_LOG_TRIVIAL(debug) << "Number of codes at section: " << numberOfCodes;

        //TODO

        free(codeSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseDataSection(unsigned char sizeOfSection)
    {
        unsigned char* dataSectionBuffer = getSection(sizeOfSection);

        parseDataVec(dataSectionBuffer);

        free(dataSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    /* Gets the whole section */
    unsigned char* getSection(unsigned char sizeOfSection)
    {
        unsigned char* sectionBuffer = (unsigned char*)malloc(sizeof(unsigned char) * sizeOfSection);
        return driver->GetNextBytes(sizeOfSection);
    }
}
