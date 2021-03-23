#ifndef ANTIWASM_MEMSEC_HPP
#define ANTIWASM_MEMSEC_HPP

#include <vector>
#include "section.hpp"
#include "../types/memtype.hpp"

class MemorySection : public Section {
private:
    std::vector<Memtype> memTypes;
public:
    MemorySection(int size, uint8_t *content, int initialPos);

    ~MemorySection();

    void addMemtype(Memtype memtype);

    Memtype *getMemtype();

    std::vector<Memtype> getMemtypeVector();
};

#endif //ANTIWASM_MEMSEC_HPP
