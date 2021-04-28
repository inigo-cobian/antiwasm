#include "funcsec.hpp"

namespace antiwasm {

FuncSection::FuncSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::FunctionId, size, content, initialPos) {}

FuncSection::~FuncSection() = default;

void FuncSection::addTypeidx(uint32_t typeidx) { typeidxVector.push_back(typeidx); }

vector<uint32_t> FuncSection::getTypeidxVector() { return typeidxVector; }

void FuncSection::displaySectionHeaderInfo() {
  cout << "    Func | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void FuncSection::displaySectionContentInfo() {
  cout << "    Func | start=" << hex << initialPos_ << " size=" << hex << size_ << " (" << typeidxVector.size()
       << ") typeidx" << endl;

  for (auto typeidx : typeidxVector) {
    cout << "( func $" << (int)typeidx << " )\n";
  }
}

} // namespace antiwasm