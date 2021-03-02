#include "../includes/scanner.hpp"

namespace antiwasm {
    int parse(const char* classFile) {
        std::shared_ptr<Driver> driver = Driver::GetInstance();
        if(!driver->OpenFile(classFile)) {
            BOOST_LOG_TRIVIAL(error) << "Cannot open file";
            return -1;
        }

        //TODO primera comprobación de tamaño

        //Magic header
        unsigned char *uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkMagicNumber(uBuffer) == false) {
            return -1;
        }

        free(uBuffer);

        //Version number
        uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkVersion(uBuffer) == false) {
            return -1;
        }

        free(uBuffer);

        //Sections
        //uBuffer = driver->GetNextSectionHeader();
        //parseSections(uBuffer);

        while( !driver->HasReachedFileSize(2) ) {
            auto* nextSectionHeader = driver->GetNextSectionHeader();
            unsigned char sectionSize = nextSectionHeader[1];
            auto* nextSectionContent = driver->GetNextBytes(sectionSize);
            parseNextSection(nextSectionHeader[0], sectionSize, nextSectionContent);
        }
        driver->CloseFile();

        return 0;
    }

    void parseNextSection(unsigned char sectionId, unsigned char sectionSize, unsigned char* sectionContent) { //TODO gestión de errores y return type
        switch (sectionId) {
            case (SectionId::Custom):
                BOOST_LOG_TRIVIAL(debug) << "Custom Section";
                break;
            case (SectionId::Type):
                BOOST_LOG_TRIVIAL(debug) << "Type Section of size " << sectionSize;
                break;
            case (SectionId::Import):
                BOOST_LOG_TRIVIAL(debug) << "Import Section of size " << sectionSize;
                break;
            case (SectionId::Function):
                BOOST_LOG_TRIVIAL(debug) << "Function Section of size " << sectionSize;
                break;
            case (SectionId::Table):
                BOOST_LOG_TRIVIAL(debug) << "Table Section of size " << sectionSize;
                break;
            case (SectionId::Memory):
                BOOST_LOG_TRIVIAL(debug) << "Memory Section of size " << sectionSize;
                break;
            case (SectionId::Global):
                BOOST_LOG_TRIVIAL(debug) << "Global Section of size " << sectionSize;
                break;
            case (SectionId::Export):
                BOOST_LOG_TRIVIAL(debug) << "Export Section of size " << sectionSize;
                break;
            case (SectionId::Start):
                BOOST_LOG_TRIVIAL(debug) << "Start Section of size " << sectionSize;
                break;
            case (SectionId::Element):
                BOOST_LOG_TRIVIAL(debug) << "Element Section of size " << sectionSize;
                break;
            case (SectionId::Code):
                BOOST_LOG_TRIVIAL(debug) << "Code Section of size " << sectionSize;
                break;
            case (SectionId::Data):
                BOOST_LOG_TRIVIAL(debug) << "Data Section of size " << sectionSize;
                break;
            default:
                //TODO error message
                BOOST_LOG_TRIVIAL(error) << "Error at section " << sectionId << " with size " << sectionSize;
        }
    }
}

