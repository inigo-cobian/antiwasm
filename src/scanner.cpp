#include "../includes/scanner.hpp"

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Enter a filename" << std::endl;
        return -1;
    }

    char* classFile = argv[1];
    BOOST_LOG_TRIVIAL(debug) << "Filename: " << classFile;

    antiwasm::parse(classFile);
}

namespace antiwasm {
    int parse(const char* classFile) {
        std::shared_ptr<Driver> driver = Driver::GetInstance(classFile);
        unsigned char *uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 4);

        //Magic header
        uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkMagicNumber(uBuffer) == false) {
            exit(0);
        }

        free(uBuffer);
        uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 4);

        //Version number
        uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkVersion(uBuffer) == false) {
            exit(0);
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
