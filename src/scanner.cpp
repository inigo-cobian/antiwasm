#include "../includes/scanner.hpp"

namespace antiwasm {
    int parse(const char* classFile) {
        std::shared_ptr<Driver> driver = Driver::GetInstance();
        if(!driver->OpenFile(classFile)) {
            BOOST_LOG_TRIVIAL(error) << "Cannot open file";
            return -1;
        }

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
        uBuffer = driver->GetNextBytes(2);
        parseSections(uBuffer);

        driver->CloseFile();

        return 0;
    }
}
