#include "memsec.hpp"

MemorySection::MemorySection(int size, uint8_t *content, int initialPos) :
        Section(SectionId::Memory, size, content, initialPos) {
    BOOST_LOG_TRIVIAL(debug) << "[memsec] Creating a Memory Section";
}

MemorySection::~MemorySection() = default;

void MemorySection::addMemtype(Memtype memtype) {
    memtypeVector.push_back(memtype);
}

std::vector<Memtype> MemorySection::getMemtypeVector() {
    return std::vector<Memtype>();
}

void MemorySection::displaySectionHeaderInfo() {
    std::cout << "  Memory | start=" << (std::hex) << initialPos_
              << " size=" << (std::hex) << size_ << std::endl;
}

void MemorySection::displayMemsecContent() {
    std::cout << "  Memory | start=" << (std::hex) << initialPos_
              << " size=" << (std::hex) << size_
              << " (" << memtypeVector.size() <<") memtypes" << std::endl;

    for(auto memtype : memtypeVector) {
        antiwasm::displayMemtype(memtype);
    }
}
