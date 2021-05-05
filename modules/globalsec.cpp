#include "globalsec.hpp"

using namespace std;
namespace antiwasm {

GlobalSection::GlobalSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::GlobalId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[globalsec] Creating a Global Section";
}

GlobalSection::~GlobalSection() = default;

void GlobalSection::addGlobal(const Global &global) { globalVector.push_back(global); }

vector<Global> GlobalSection::getGlobalVector() { return globalVector; }

void GlobalSection::displaySectionHeaderInfo() {
  cout << "  Global | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void GlobalSection::displaySectionContentInfo() {
  cout << "  Global | start=" << hex << initialPos_ << " size=" << hex << size_ << " (" << globalVector.size()
       << ") globals" << endl;

  size_t index = 0;
  for (const auto &globaltype : globalVector) {
    // TODO
  }
  cout << endl;
}

} // namespace antiwasm