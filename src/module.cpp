#include "module.hpp"
#include "section_index.hpp"

namespace antiwasm {

    //TODO create parsers for the different sections
    size_t parseSections(unsigned char* buffer) {
        if(buffer[0] == Section::Custom) {
            std::cout << "Custom Section" << std::endl;
        }
        else if(buffer[0] == Section::Type) {
            std::cout << "Type Section" << std::endl;
        }
        else if(buffer[0] == Section::Import) {
            std::cout << "Import Section" << std::endl;
        }
        else if(buffer[0] == Section::Function) {
            std::cout << "Function Section" << std::endl;
        }
        else if(buffer[0] == Section::Table) {
            std::cout << "Table Section" << std::endl;
        }
        else if(buffer[0] == Section::Memory) {
            std::cout << "Memory Section" << std::endl;
        }
        else if(buffer[0] == Section::Global) {
            std::cout << "Global Section" << std::endl;
        }
        else if(buffer[0] == Section::Export) {
            std::cout << "Export Section" << std::endl;
        }
        else if(buffer[0] == Section::Start) {
            std::cout << "Start Section" << std::endl;
        }
        else if(buffer[0] == Section::Element) {
            std::cout << "Element Section" << std::endl;
        }
        else if(buffer[0] == Section::Code) {
            std::cout << "Code Section" << std::endl;
        }
        else if(buffer[0] == Section::Data) {
            std::cout << "Data Section" << std::endl;
        }
        return 0;
    }
    

}
