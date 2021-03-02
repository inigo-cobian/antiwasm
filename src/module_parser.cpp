#include "../includes/module_parser.hpp"

namespace antiwasm {
/*
    std::shared_ptr<Driver> driver;

    unsigned char* parseCustomSection(unsigned char sizeOfSection)
    {
        return nullptr; //TODO
    }
    
    unsigned char* parseTypeSection(unsigned char sizeOfSection)
    {
        unsigned char* typeSectionBuffer = getSectionContent(sizeOfSection);

        parseFuncTypeVec(typeSectionBuffer);

        free(typeSectionBuffer);
    }

    unsigned char* parseImportSection(unsigned char sizeOfSection)
    {
        unsigned char* importSectionBuffer = getSectionContent(sizeOfSection);

        parseImportVec(importSectionBuffer);

        free(importSectionBuffer);
    }

    unsigned char* parseFunctionSection(unsigned char sizeOfSection)
    {
        unsigned char* functionSectionBuffer = getSectionContent(sizeOfSection);

        int pointer = 1;
        int numberOfFunctions = functionSectionBuffer[0];
        BOOST_LOG_TRIVIAL(debug) << "Number of functions at section: " << numberOfFunctions;

        //TODO

        free(functionSectionBuffer);
    }

    unsigned char* parseTableSection(unsigned char sizeOfSection)
    {
        unsigned char* tableSectionBuffer = getSectionContent(sizeOfSection);

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
                BOOST_LOG_TRIVIAL(error) << "Not a table";
                return nullptr;
            }
        }

        free(tableSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseMemorySection(unsigned char sizeOfSection)
    {
        unsigned char* memorySectionBuffer = getSectionContent(sizeOfSection);

        BOOST_LOG_TRIVIAL(debug)  << "Number of memories at section: " << memorySectionBuffer[1];

        //Memory is composed by a limit
        parseLimitVec(memorySectionBuffer);

        free(memorySectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseGlobalSection(unsigned char sizeOfSection)
    {
        unsigned char* globalSectionBuffer = getSectionContent(sizeOfSection);

        parseGlobalVec(globalSectionBuffer);

        free(globalSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseExportSection(unsigned char sizeOfSection)
    {
        unsigned char* exportSectionBuffer = getSectionContent(sizeOfSection);

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
        unsigned char* elementSectionBuffer = getSectionContent(sizeOfSection);

        parseElementVec(elementSectionBuffer);

        free(elementSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseCodeSection(unsigned char sizeOfSection)
    {
        unsigned char* codeSectionBuffer = getSectionContent(sizeOfSection);

        int pointer = 1;
        int numberOfCodes = codeSectionBuffer[0];
        BOOST_LOG_TRIVIAL(debug) << "Number of codes at section: " << numberOfCodes;

        //TODO

        free(codeSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    unsigned char* parseDataSection(unsigned char sizeOfSection)
    {
        unsigned char* dataSectionBuffer = getSectionContent(sizeOfSection);

        parseDataVec(dataSectionBuffer);

        free(dataSectionBuffer);
        return driver->GetNextSectionHeader();
    }

    // Gets the whole section
    unsigned char* getSectionContent(unsigned char sizeOfSection)
    {
        return driver->GetNextBytes(sizeOfSection);
    }
*/
}
