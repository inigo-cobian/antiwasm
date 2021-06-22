#include "exportsec.hpp"

namespace antiwasm {

ExportSection::ExportSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::ExportId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[exportsec] Creating a Export Section";
}

ExportSection::~ExportSection() = default;

void ExportSection::addExport(const Export &export_) {
  BOOST_LOG_TRIVIAL(trace) << "[exportsec] Adding a new export to the vector at pos [" << exportVector.size() << "]";
  exportVector.push_back(export_);
}

std::vector<Export> ExportSection::getExportVector() { return exportVector; }

void ExportSection::displaySectionHeaderInfo() {
  std::cout << "  Export | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void ExportSection::displaySectionContentInfo() {
  std::cout << "  Export | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;

  size_t index = 0;
  std::for_each(exportVector.begin(), exportVector.end(), [index](const Export &export_) mutable {
    std::cout << export_.getAsText() << std::endl;
    index++;
  });
}
} // namespace antiwasm