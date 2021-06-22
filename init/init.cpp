#include "displayer.hpp"
#include "module_parser.hpp"
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/program_options.hpp>
#include <mpi.h>
#include <iostream>

#define BOOST_LOG_WITHOUT_DEBUG_OUTPUT

using namespace std;
using namespace antiwasm;

void init_logging(boost::log::trivial::severity_level severityLevel) { // TODO change the format of the log
  boost::log::core::get()->set_filter(boost::log::trivial::severity >= severityLevel);
}

int main(int argc, char **argv) {

  int process_rank, size_Of_Cluster;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
  MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);

  if(process_rank == 0) {

    // Declare the supported options.
    boost::program_options::options_description argDescription("Allowed options for antiwasm");
    argDescription.add_options()("help", "produce this help message")(
        "filename", boost::program_options::value<string>(),
        "route of the .wasm file")("debug", boost::program_options::value<char>(),
                                   "set the debugging tools on")("verbose",
                                                                 "display relevant information about the decompiling process")("pedantic",
                                                                            "display every single datum about the decompiling process")("section",
                                                                                                   boost::
                                                                                                       program_options::
                                                                                                           value<
                                                                                                               string>(),
                                                                                                   "selects a section for displaying");

    boost::program_options::variables_map variablesMap;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, argDescription), variablesMap);
    boost::program_options::notify(variablesMap);

    // If one of the options is set to 'help'...
    if (variablesMap.count("help")) {
      // Display the options_description
      cout << argDescription << "\n";
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
        cout << "Unknown option at debug level\n";
        return 1;
      }
    } else {
      init_logging(boost::log::trivial::debug); // TODO if release set as INFO
    }

    if (variablesMap.count("verbose")) {
      Displayer::SetLoggingLevel(VERBOSE);
    }

    if (variablesMap.count("pedantic")) {
      Displayer::SetLoggingLevel(PEDANTIC);
    }

    if (variablesMap.count("section")) {
      string section = variablesMap["section"].as<string>();
      if (Displayer::setSectionToDisplay(section)) {
        cout << "Parsing section: " << hex << section << endl;
      } else {
        cout << "Unrecognized section to parse \"" << section << "\"\n";
        return 1;
      }
    }

    if (variablesMap.count("filename")) {
      cout << "Decoding \'" << variablesMap["filename"].as<string>() << "'\n";
      antiwasm::parse(variablesMap["filename"].as<string>().c_str());
    } else {
      cout << "No filename set\n";
      return 1;
    }
  }
  MPI_Finalize();
}
