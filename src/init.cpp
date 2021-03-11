#include "../includes/scanner.hpp"
#include "../includes/displayer.hpp"
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/test/unit_test_parameters.hpp>

#define BOOST_LOG_WITHOUT_DEBUG_OUTPUT

void init_logging(boost::log::trivial::severity_level severityLevel) {
    boost::log::core::get()->set_filter(
            boost::log::trivial::severity >= severityLevel
    );
}


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
             boost::program_options::value<char>(),
             "set the debugging tools on")
            ("verbose",
             "display relevant information about the decompiling process")
            ("pedantic",
             "display every single datum about the decompiling process");

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

    Displayer::SetLoggingLevel(INFO);

    if (variablesMap.count("debug")) {
        Displayer::SetLoggingLevel(DEBUG);
        int debugLevel = variablesMap["debug"].as<char>();
        switch (debugLevel) {
            case 't':
                init_logging(boost::log::trivial::trace);
                break;
            case 'd':
                init_logging(boost::log::trivial::debug);
                break;
            case 'i':
                init_logging(boost::log::trivial::info);
                break;
            case 'w':
                init_logging(boost::log::trivial::warning);
                break;
            case 'e':
                init_logging(boost::log::trivial::error);
                break;
            case 'f':
                init_logging(boost::log::trivial::fatal);
                break;
            default:
                std::cout << "Unknown option at debug level\n";
                return 0;
        }
    } else {
        init_logging(boost::log::trivial::debug); //TODO if release set as INFO
    }

    if (variablesMap.count("verbose")) {
        Displayer::SetLoggingLevel(VERBOSE);
    }

    if (variablesMap.count("pedantic")) {
        Displayer::SetLoggingLevel(PEDANTIC);
    }

    if (variablesMap.count("filename")) {
        std::cout << "Compiling " << variablesMap["filename"].as<std::string>() << "'\n";
        antiwasm::parse(variablesMap["filename"].as<std::string>().c_str());
    } else {
        std::cout << "No filename set\n";
        return 0;
    }

    //TODO exception if unknown option
}
