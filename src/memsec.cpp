#include "../includes/memsec.hpp"

MemorySection::MemorySection(antiwasm::SectionId sectionId, int size, unsigned char *content, int initialPos) : Section(sectionId, size, content, initialPos) {
    BOOST_LOG_TRIVIAL(debug) << "[memsec] Creating a Memory Section";
}

MemorySection::~MemorySection() {

}

void MemorySection::addMemtype(Memtype *memtype) {
    //TODO
}

Memtype *MemorySection::getMemtype() {
    return nullptr;
}

std::vector<Memtype> MemorySection::getMemtypeVector() {
    return std::vector<Memtype>();
}
