#include "memsec.hpp"

MemorySection::MemorySection(int size, uint8_t *content, int initialPos) :
        Section(SectionId::Memory, size, content, initialPos) {
    BOOST_LOG_TRIVIAL(debug) << "[memsec] Creating a Memory Section";
}

MemorySection::~MemorySection() {

}

void MemorySection::addMemtype(Memtype memtype) {
    memTypes.push_back(memtype);
}

std::vector<Memtype> MemorySection::getMemtypeVector() {
    return std::vector<Memtype>();
}
