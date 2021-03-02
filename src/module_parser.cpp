#include "../includes/module_parser.hpp"

namespace antiwasm {

    void parseNextSection(unsigned char sectionId, int sectionSize, unsigned char* sectionContent) { //TODO gestión de errores y return type

        BOOST_LOG_TRIVIAL(debug) << "Info of the next section [" << (unsigned int)sectionId << "] with size " << (unsigned int)sectionSize;
        switch (sectionId) {
            case (SectionId::Custom):
                parseCustomSection(sectionSize, sectionContent);
                break;
            case (SectionId::Type):
                parseTypeSection(sectionSize, sectionContent);
                break;
            case (SectionId::Import):
                parseImportSection(sectionSize, sectionContent);
                break;
            case (SectionId::Function):
                parseFunctionSection(sectionSize, sectionContent);
                break;
            case (SectionId::Table):
                parseTableSection(sectionSize, sectionContent);
                break;
            case (SectionId::Memory):
                parseMemorySection(sectionSize, sectionContent);
                break;
            case (SectionId::Global):
                parseGlobalSection(sectionSize, sectionContent);
                break;
            case (SectionId::Export):
                parseExportSection(sectionSize, sectionContent);
                break;
            case (SectionId::Start):
                parseStartSection(sectionSize, sectionContent);
                break;
            case (SectionId::Element):
                parseElementSection(sectionSize, sectionContent);
                break;
            case (SectionId::Code):
                parseCodeSection(sectionSize, sectionContent);
                break;
            case (SectionId::Data):
                parseDataSection(sectionSize, sectionContent);
                break;
            default:
                //TODO pretty error message
                BOOST_LOG_TRIVIAL(error) << "Error at section " << sectionId << " with size " << sectionSize;
        }
    }

    unsigned char* parseCustomSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }
    
    unsigned char* parseTypeSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseImportSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseFunctionSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseTableSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseMemorySection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseGlobalSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseExportSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseStartSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseElementSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseCodeSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }

    unsigned char* parseDataSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return nullptr; //TODO
    }
}
