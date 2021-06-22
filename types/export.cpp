#include "export.hpp"

namespace antiwasm {
Export::Export(UTF8Name  name_, ExportDesc exportDesc_, uint32_t index_)
    : name(std::move(name_)), exportDesc(exportDesc_), index(index_) {

}

std::string Export::getAsText() const {
  return std::string{""}; // TODO
}

ExportDesc parseExportDesc(uint8_t exportDescContent) {
  if(exportDescContent >= 0x00 && exportDescContent <= 0x03) {
    return static_cast<ExportDesc>(exportDescContent);
  }
  return ExportDesc::invalid_exportDesc;
}

Export parseExport(const uint8_t *exportContent) {
  auto sizeOfName = transformLeb128ToUnsignedInt32(exportContent);
  size_t pointer = sizeOfLeb128(exportContent);
  auto name = parseUTF8Name(exportContent + pointer, sizeOfName);
  pointer += sizeOfName;

  auto exportDesc = parseExportDesc(exportContent[pointer]);
  pointer++;
  if(exportDesc == invalid_exportDesc) {
    Export export_{name, exportDesc, 0};
    export_.addError(generateError(fatal, invalidExportDescAtExport, 0));
    return export_;
  }

  auto index = transformLeb128ToUnsignedInt32(exportContent + pointer);
  pointer += sizeOfLeb128(exportContent + pointer);

  Export export_{name, exportDesc, index};
  export_.setNBytes(pointer);
  return export_;
}

} // namespace antiwasm
