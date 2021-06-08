#include "datasec.hpp"

namespace antiwasm {

DataSection::DataSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::DataId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[datasec] Creating a Data Section";
}

DataSection::~DataSection() = default;

void DataSection::addData(const Data &data) { dataVector.push_back(data); }

std::vector<Data> DataSection::getDataVector() { return dataVector; }

void DataSection::displaySectionHeaderInfo() {
  std::cout << "    Data | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void DataSection::displaySectionContentInfo() {
  std::cout << "    Data | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;

  std::for_each(dataVector.begin(), dataVector.end(),
                [](const Data &data) { std::cout << data.getAsText() << std::endl; });

  std::cout << std::endl;
}
} // namespace antiwasm