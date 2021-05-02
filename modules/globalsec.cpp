#include "globalsec.hpp"

using namespace std;
namespace antiwasm {

GlobalSection::GlobalSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::GlobalId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[globalsec] Creating a Global Section";
}

GlobalSection::~GlobalSection() = default;

void GlobalSection::addImport(const Globaltype &globaltype) { globaltypeVector.push_back(globaltype); }

vector<Globaltype> GlobalSection::getGlobaltypeVector() { return globaltypeVector; }

void GlobalSection::displaySectionHeaderInfo() {
  cout << "  Global | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void GlobalSection::displaySectionContentInfo() {
  cout << "  Global | start=" << hex << initialPos_ << " size=" << hex << size_ << " (" << globaltypeVector.size()
       << ") globals" << endl;

  size_t index = 0;
  for (const auto &globaltype : globaltypeVector) {
    // TODO
  }
}

} // namespace antiwasm