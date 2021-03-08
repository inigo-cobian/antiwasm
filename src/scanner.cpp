#include "../includes/scanner.hpp"

namespace antiwasm {
    int parse(const char *classFile) {
        std::shared_ptr<Driver> driver = Driver::GetInstance();
        if (!driver->OpenFile(classFile)) {
            BOOST_LOG_TRIVIAL(error) << "[scanner] Cannot open file";
            return -1;
        }

        //TODO primera comprobación de tamaño

        //Generate Module
        Module module(driver->GetFileSize());

        //Magic header
        unsigned char *uBuffer = driver->GetNextBytes(4);
        if (antiwasm::checkMagicNumber(uBuffer) == false) {
            return -1;
        }

        free(uBuffer);

        //Version number
        uBuffer = driver->GetNextBytes(4);
        if (antiwasm::checkVersion(uBuffer) == false) {
            return -1;
        }

        free(uBuffer);

        //Sections
        while (!driver->HasReachedFileSize(2)) {
            auto sectionPosition = driver->GetCurrentPos();
            auto *nextSectionHeader = driver->GetNextSectionHeader();
            int sectionSize = nextSectionHeader[1];
            auto *nextSectionContent = driver->GetNextBytes(sectionSize);
            auto nextSection = parseNextSection(nextSectionHeader[0], sectionSize, nextSectionContent, sectionPosition);

            BOOST_LOG_TRIVIAL(trace) << "[scanner] Id: " << std::hex << (int) nextSectionHeader[0];
            BOOST_LOG_TRIVIAL(trace) << "[scanner] Size: " << std::hex << sectionSize;

            if (nextSection.getSectionId() != Error) {
                nextSection.displaySectionInfo();
                module.addSection(nextSection);
            } else { //TODO manage error
                break;
            }

        }
        driver->CloseFile();

        return 0;
    }
}

