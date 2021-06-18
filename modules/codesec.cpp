#include "codesec.hpp"

namespace antiwasm {

CodeSection::CodeSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::CodeId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[codesec] Creating a Code Section";
}

CodeSection::~CodeSection() = default;

void CodeSection::addCode(const Code &code) { codeVector.push_back(code); }

std::vector<Code> CodeSection::getCodeVector() { return codeVector; }

void CodeSection::displaySectionHeaderInfo() {
  std::cout << "    Code | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void CodeSection::displaySectionContentInfo() {
  std::cout << "    Code | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;

  /*
  size_t index = 0;
  std::for_each(dataVector.begin(), dataVector.end(),
                [](const Data &data) { std::cout << data.getAsText() << std::endl; });

  std::cout << std::endl;
   */
}
} // namespace antiwasm