#include "../includes/module_parser.hpp"

namespace antiwasm {

    Section parseNextSection(unsigned char sectionId, int sectionSize,
                             unsigned char *sectionContent, int sectionPos) { //TODO gestión de errores y return type

        BOOST_LOG_TRIVIAL(debug) << "[module_parser] Info of the next section [" << (unsigned int) sectionId << "] with size "
                                 << (unsigned int) sectionSize;
        switch (sectionId) {
            case (SectionId::Custom):
                parseCustomSection(sectionSize, sectionContent);
                return Section(SectionId::Custom, sectionSize, sectionContent, sectionPos);
            case (SectionId::Type):
                parseTypeSection(sectionSize, sectionContent);
                return Section(SectionId::Type, sectionSize, sectionContent, sectionPos);
            case (SectionId::Import):
                parseImportSection(sectionSize, sectionContent);
                return Section(SectionId::Import, sectionSize, sectionContent, sectionPos);
            case (SectionId::Function):
                parseFunctionSection(sectionSize, sectionContent);
                return Section(SectionId::Function, sectionSize, sectionContent, sectionPos);
            case (SectionId::Table):
                parseTableSection(sectionSize, sectionContent);
                return Section(SectionId::Table, sectionSize, sectionContent, sectionPos);
            case (SectionId::Memory):
                parseMemorySection(sectionSize, sectionContent);
                return Section(SectionId::Memory, sectionSize, sectionContent, sectionPos);
            case (SectionId::Global):
                parseGlobalSection(sectionSize, sectionContent);
                return Section(SectionId::Global, sectionSize, sectionContent, sectionPos);
            case (SectionId::Export):
                parseExportSection(sectionSize, sectionContent);
                return Section(SectionId::Export, sectionSize, sectionContent, sectionPos);
            case (SectionId::Start):
                parseStartSection(sectionSize, sectionContent);
                return Section(SectionId::Start, sectionSize, sectionContent, sectionPos);
            case (SectionId::Element):
                parseElementSection(sectionSize, sectionContent);
                return Section(SectionId::Element, sectionSize, sectionContent, sectionPos);
            case (SectionId::Code):
                parseCodeSection(sectionSize, sectionContent);
                return Section(SectionId::Code, sectionSize, sectionContent, sectionPos);
            case (SectionId::Data):
                parseDataSection(sectionSize, sectionContent);
                return Section(SectionId::Data, sectionSize, sectionContent, sectionPos);
            default:
                //TODO pretty error message
                BOOST_LOG_TRIVIAL(error) << "[module_parser] Error at section " << std::hex << (unsigned int) sectionId << " with size "
                                         << sectionSize;
                return Section(SectionId::Error, -1, nullptr, 0);
        }
    }

    int parseCustomSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseTypeSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseImportSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseFunctionSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseTableSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseMemorySection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseGlobalSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseExportSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseStartSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseElementSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseCodeSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }

    int parseDataSection(int sizeOfSection, unsigned char *sectionContent) {
        return 0; //TODO
    }
}
