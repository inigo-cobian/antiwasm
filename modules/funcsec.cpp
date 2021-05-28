#include "funcsec.hpp"

namespace antiwasm {

FuncSection::FuncSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::FunctionId, size, content, initialPos) {}

FuncSection::~FuncSection() = default;

void FuncSection::addTypeidx(uint32_t typeidx) { typeidxVector.push_back(typeidx); }

std::vector<uint32_t> FuncSection::getTypeidxVector() { return typeidxVector; }

void FuncSection::displaySectionHeaderInfo() {
  std::cout << "    Func | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void FuncSection::displaySectionContentInfo() {
  std::cout << "    Func | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << " (" << typeidxVector.size()
       << ") typeidx" << std::endl;

  for (auto typeidx : typeidxVector) {
    std::cout << "( func $" << (int)typeidx << " )\n";
  }
}

} // namespace antiwasm