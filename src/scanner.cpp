#include "scanner.hpp"
#include "lexems.hpp"
#include "header.hpp"

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
        size_t size = 0;
        size_t pointer = 0;
        char *buffer = new char[4];  //TODO which size?
        unsigned char *uBuffer; //pointer to the reading buffer

        std::ifstream inputFile(classFile);
	    inputFile.seekg(0, std::ios::end); // set the pointer to the end
	    size = inputFile.tellg() ; // get the length of the file
	    std::cout << "Size of file: " << size << std::endl;
	    inputFile.seekg(0, std::ios::beg); // set the pointer to the beginning

        //Magic header
        inputFile.read(buffer, 4);
        uBuffer = (unsigned char*)buffer;

        if(antiwasm::checkMagicNumber(uBuffer) == false) {
            exit(0);
        }

        //Version number
        inputFile.seekg(INDEX_VERSION, std::ios::beg); 
        inputFile.read(buffer, 4);
        uBuffer = (unsigned char*)buffer;

        if(antiwasm::checkVersion(uBuffer) == false) {
            exit(0);
        }


        inputFile.close();

        return 0;
    }
}
