#include "../includes/module_parser.hpp"

namespace antiwasm {

    int parseNextSection(unsigned char sectionId, int sectionSize, unsigned char* sectionContent) { //TODO gestión de errores y return type

        BOOST_LOG_TRIVIAL(debug) << "Info of the next section [" << (unsigned int)sectionId << "] with size " << (unsigned int)sectionSize;
        switch (sectionId) {
            case (SectionId::Custom):
                parseCustomSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Type):
                parseTypeSection(sectionSize, sectionContent);
                return 0;
                case (SectionId::Import):
                parseImportSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Function):
                parseFunctionSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Table):
                parseTableSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Memory):
                parseMemorySection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Global):
                parseGlobalSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Export):
                parseExportSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Start):
                parseStartSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Element):
                parseElementSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Code):
                parseCodeSection(sectionSize, sectionContent);
                return 0;
            case (SectionId::Data):
                parseDataSection(sectionSize, sectionContent);
                return 0;
            default:
                //TODO pretty error message
                BOOST_LOG_TRIVIAL(error) << "Error at section " << sectionId << " with size " << sectionSize;
                return 1;
        }
    }

    int parseCustomSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseTypeSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseImportSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseFunctionSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseTableSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseMemorySection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseGlobalSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseExportSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseStartSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseElementSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseCodeSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }

    int parseDataSection(int sizeOfSection, unsigned char* sectionContent)
    {
        return 0; //TODO
    }
}
