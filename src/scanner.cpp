#include "../includes/scanner.hpp"

namespace antiwasm {
    int parse(const char* classFile) {
        std::shared_ptr<Driver> driver = Driver::GetInstance();
        if(!driver->OpenFile(classFile)) {
            BOOST_LOG_TRIVIAL(error) << "Cannot open file";
            return -1;
        }

        unsigned char *uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 4);

        //Magic header
        uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkMagicNumber(uBuffer) == false) {
            return -1;
        }

        free(uBuffer);
        uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 4);

        //Version number
        uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkVersion(uBuffer) == false) {
            return -1;
        }

        free(uBuffer);
        uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 2);

        //Sections
        uBuffer = driver->GetNextBytes(2);
        parseSections(uBuffer);

        driver->CloseFile();

        return 0;
    }
}
