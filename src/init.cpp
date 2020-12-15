#include "../includes/init.hpp"

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Enter a filename" << std::endl;
        return -1;
    }

    char* classFile = argv[1];
    BOOST_LOG_TRIVIAL(debug) << "Filename: " << classFile;

    antiwasm::parse(classFile);
}

