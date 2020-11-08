#include "scanner.hpp"

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Enter a filename" << std::endl;
        return -1;
    }

    char* classFile = argv[1];
    std::cout << "Filename: " << classFile << std::endl;

    antiwasm::parse(classFile);
}

namespace antiwasm {
    int parse(const char* classFile) {
        Driver *driver = driver->GetInstance(classFile);
        unsigned char *uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 5);

        //Magic header
        uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkMagicNumber(uBuffer) == false) {
            exit(0);
        }

        free(uBuffer);
        uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 5);

        //Version number
        uBuffer = driver->GetNextBytes(4);
        if(antiwasm::checkVersion(uBuffer) == false) {
            exit(0);
        }

        free(uBuffer);
        uBuffer = (unsigned char*)malloc(sizeof(unsigned char) * 5);

        //Sections
        uBuffer = driver->GetNextBytes(1);
        parseSections(uBuffer);

        driver->CloseFile();

        return 0;
    }
}
