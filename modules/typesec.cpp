#include "typesec.hpp"

namespace antiwasm {

TypeSection::TypeSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::TypeId, size, content, initialPos) {}

TypeSection::~TypeSection() {}

void TypeSection::addFunctype(Functype functype) { functypeVector.push_back(functype); }

std::vector<Functype> TypeSection::getFunctypeVector() { return functypeVector; }

void TypeSection::displaySectionHeaderInfo() {
  std::cout << "    Type | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void TypeSection::displaySectionContentInfo() {
  std::cout << "    Type | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << " (" << functypeVector.size()
       << ") functypes" << std::endl;

  size_t index = 0;
  for (const auto &functype : functypeVector) {
    std::stringstream functypeAsText;
    bool isEmptyFunc = true;
    functypeAsText << "( func $" << index++ << " ";
    if (!functype.parameterType.valtypeVector.empty()) {
      isEmptyFunc = false;
      functypeAsText << getParamAsText(functype);
    }
    if (!functype.returnType.valtypeVector.empty()) {
      isEmptyFunc = false;
      functypeAsText << getResultAsText(functype);
    }
    functypeAsText << (isEmptyFunc ? ")" : "\n)");
    std::cout << functypeAsText.str() << std::endl;
  }
}

std::string TypeSection::getParamAsText(const Functype &functype) const {
  std::stringstream paramText;
  paramText << "\n ( param ";
  for (const auto &paramValtype : functype.parameterType.valtypeVector) {
    paramText << paramValtype.getAsText() << " ";
  }
  paramText << ")";
  return paramText.str();
}

std::string TypeSection::getResultAsText(const Functype &functype) const {
  std::stringstream resultText;
  resultText << "\n ( result ";
  for (const auto &resultValtype : functype.returnType.valtypeVector) {
    resultText << resultValtype.getAsText() + " ";
  }
  resultText << ")";
  return resultText.str();
}

} // namespace antiwasm