#ifndef ANTIWASM_SECTIONHEADER_HPP
#define ANTIWASM_SECTIONHEADER_HPP

#include "section.hpp"
#include <cstdint>

namespace antiwasm {
struct SectionHeader {
  SectionId id;
  int pos;
  int size;
  std::shared_ptr<uint8_t> content;
};
} // namespace antiwasm

#endif // ANTIWASM_SECTIONHEADER_HPP
