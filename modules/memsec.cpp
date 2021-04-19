#include "memsec.hpp"

namespace antiwasm {

MemorySection::MemorySection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::Memory, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[memsec] Creating a Memory Section";
}

MemorySection::~MemorySection() = default;

void MemorySection::addMemtype(Memtype memtype) { memtypeVector.push_back(memtype); }

vector<Memtype> MemorySection::getMemtypeVector() { return vector<Memtype>(); }

void MemorySection::displaySectionHeaderInfo() {
  cout << "  Memory | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void MemorySection::displaySectionContentInfo() {
  cout << "  Memory | start=" << hex << initialPos_ << " size=" << hex << size_ << " ("
            << memtypeVector.size() << ") memtypes" << endl;

  size_t index = 0;
  for (const auto& memtype : memtypeVector) {
    stringstream memtypeAsText;
    memtypeAsText << "( memory $" << index++ << " ";
    if(memtype.limit.type == limit_min) {
      memtypeAsText << memtype.limit.min << " )\n";
    } else if (memtype.limit.type == limit_min_max) {
      memtypeAsText << memtype.limit.min << " " << memtype.limit.max << " )\n";
    }
    cout << memtypeAsText.str() << endl;
  }
}

} // namespace antiwasm