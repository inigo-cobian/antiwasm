#include "globalsec.hpp"

namespace antiwasm {

GlobalSection::GlobalSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::GlobalId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[globalsec] Creating a Global Section";
}

GlobalSection::~GlobalSection() = default;

void GlobalSection::addGlobal(const Global &global) { globalVector.push_back(global); }

std::vector<Global> GlobalSection::getGlobalVector() { return globalVector; }

void GlobalSection::displaySectionHeaderInfo() {
  std::cout << "  Global | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void GlobalSection::displaySectionContentInfo() {
  std::cout << "  Global | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << " (" << globalVector.size()
       << ") globals" << std::endl;

  // (global (;0;) (mut i32) (i32.const 1998848))
  size_t index = 0;
  std::for_each(globalVector.begin(), globalVector.end(),
                [](const Global &global){std::cout << global.getAsText() << std::endl;}
                );

  std::cout << std::endl;
}

} // namespace antiwasm