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

void MemorySection::displayMemsecContent() {
  cout << "  Memory | start=" << hex << initialPos_ << " size=" << hex << size_ << " ("
            << memtypeVector.size() << ") memtypes" << endl;

  for (auto memtype : memtypeVector) {
    memtype.displayContentInfo();
  }
}

} // namespace antiwasm