#include "../includes/scanner.hpp"
#include "../includes/logger.hpp"
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/test/unit_test_parameters.hpp>
#define BOOST_LOG_WITHOUT_DEBUG_OUTPUT

int main(int argc, char **argv) {

    // Declare the supported options.
    boost::program_options::options_description argDescription("Allowed options for antiwasm");
    argDescription.add_options()
            ("help",
             "produce this help message")
            ("filename",
             boost::program_options::value<std::string>(),
             "route of the .wasm file")
            ("debug",
             "set the debugging tools on")
            ("verbose",
             "display relevant information about the decompiling process")
            ("pedantic",
             "display every single datum about the decompiling process")
             ;

    boost::program_options::variables_map variablesMap;
    boost::program_options::store(
            boost::program_options::parse_command_line(
                    argc, argv, argDescription), variablesMap);
    boost::program_options::notify(variablesMap);

    //If one of the options is set to 'help'...
    if (variablesMap.count("help")) {
        //Display the options_description
        std::cout << argDescription << "\n";
        return 0;
    }

    std::unique_ptr<Logger> logger = std::make_unique<Logger>();
    logger->SetLoggingLevel(INFO);

    if (variablesMap.count("debug")) {
        logger->SetLoggingLevel(DEBUG);
    }

    if (variablesMap.count("verbose")) {
        logger->SetLoggingLevel(VERBOSE);
    }

    if (variablesMap.count("pedantic")) {
        logger->SetLoggingLevel(PEDANTIC);
    }

    if (variablesMap.count("filename")) {
        std::cout << "Compiling " << variablesMap["filename"].as<std::string>() << "'\n";
        antiwasm::parse( variablesMap["filename"].as<std::string>().c_str() );
    }
    else {
        std::cout << "No filename set\n";
        return 0;
    }

    //TODO exception if unknown option
}
