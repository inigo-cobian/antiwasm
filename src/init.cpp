#include "../includes/init.hpp"

int main(int argc, char **argv) {

    // Declare the supported options.
    boost::program_options::options_description argDescription("Allowed options for [my_program]");
    argDescription.add_options()
            ("help",
             "produce this help message")
            ("filename",
             boost::program_options::value<std::string>(),
             "route of the .wasm file");

    boost::program_options::variables_map variablesMap;
    boost::program_options::store(
            boost::program_options::parse_command_line(
                    argc, argv, argDescription), variablesMap);
    boost::program_options::notify(variablesMap);

    //If one of the options is set to 'help'...
    if (variablesMap.count("help"))
    {
        //Display the options_description
        std::cout << argDescription << "\n";
    }

    if (variablesMap.count("filename"))
    {
        std::cout
                << "Compiling " << variablesMap["filename"].as<std::string>() << "'\n";
        antiwasm::parse( variablesMap["filename"].as<std::string>().c_str() );
    }
    else
    {
        std::cout
                << "No filename set\n";
    }

}
