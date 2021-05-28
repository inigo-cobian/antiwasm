#include "memsec.hpp"

namespace antiwasm {

MemorySection::MemorySection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::MemoryId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[memsec] Creating a MemoryId Section";
}

MemorySection::~MemorySection() = default;

void MemorySection::addMemtype(const Memtype &memtype) { memtypeVector.push_back(memtype); }

std::vector<Memtype> MemorySection::getMemtypeVector() { return memtypeVector; }

void MemorySection::displaySectionHeaderInfo() {
  std::cout << "  Memory | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void MemorySection::displaySectionContentInfo() {
  std::cout << "  Memory | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << " (" << memtypeVector.size()
       << ") memtypes" << std::endl;

  size_t index = 0;
  for (const auto &memtype : memtypeVector) {
    std::stringstream memtypeAsText;
    memtypeAsText << "( memory $" << index++ << " ";
    if (memtype.limit.type == limit_min) {
      memtypeAsText << memtype.limit.min << " )\n";
    } else if (memtype.limit.type == limit_min_max) {
      memtypeAsText << memtype.limit.min << " " << memtype.limit.max << " )\n";
    }
    std::cout << memtypeAsText.str() << std::endl;
  }
}

} // namespace antiwasm