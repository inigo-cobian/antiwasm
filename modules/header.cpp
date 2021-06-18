#include "header.hpp"

namespace antiwasm {
bool checkMagicNumber(const std::unique_ptr<uint8_t> header) {
  if (header.get()[0] == 0x00 && header.get()[1] == 0x61 && header.get()[2] == 0x73 && header.get()[3] == 0x6D) {
    BOOST_LOG_TRIVIAL(debug) << "[header] Magic header found";
    return true;
  } else {
    BOOST_LOG_TRIVIAL(error) << "[header] This file has no magic header. Compilation failed.";
    printf("%02x %02x %02x %02x\n", header.get()[0], header.get()[1], header.get()[2], header.get()[3]);
    return false;
  }
}

bool checkVersion(const std::unique_ptr<uint8_t> version) {
  if (version.get()[0] == 0x01 && version.get()[1] == 0x00 && version.get()[2] == 0x00 && version.get()[3] == 0x00) {
    BOOST_LOG_TRIVIAL(debug) << "[header] Version 1.0";
    return true;
  } else {
    BOOST_LOG_TRIVIAL(warning) << "[header] Unknown version. Some "
                                  "functionalities might not be supported.";
    return false;
  }
}
} // namespace antiwasm
