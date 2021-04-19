#include "typesec.hpp"

namespace antiwasm {

TypeSection::TypeSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::Type, size, content, initialPos) {}

TypeSection::~TypeSection() {}

void TypeSection::addFunctype(Functype functype) { functypeVector.push_back(functype); }

vector<Functype> TypeSection::getFunctypeVector() { return functypeVector; }

void TypeSection::displaySectionHeaderInfo() {
  cout << "    Type | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void TypeSection::displaySectionContentInfo() {
  cout << "    Type | start=" << hex << initialPos_ << " size=" << hex << size_
            << " (" << functypeVector.size() << ") functypes" << endl;

  for (const auto& functype : functypeVector) {
    stringstream functypeAsText;
    bool isEmptyFunc = true;
    functypeAsText << "( func ";
    if (!functype.parameterType.valtypeVector.empty()) {
      isEmptyFunc = false;
      functypeAsText << getParamAsText(functype);
      //getParamAsText(functype);
    }
    if (!functype.returnType.valtypeVector.empty()) {
      isEmptyFunc = false;
      functypeAsText << getResultAsText(functype);
    }
    functypeAsText << (isEmptyFunc ? ")" : "\n)");
    cout << functypeAsText.str() << endl;
  }
}
string TypeSection::getParamAsText(const Functype &functype) const {
  stringstream paramText;
  for(const auto& paramValtype : functype.parameterType.valtypeVector) {
    paramText << "\n ( param " + paramValtype.getAsText() + ")";
  }
  return paramText.str();
}

string TypeSection::getResultAsText(const Functype &functype) const {
  stringstream resultText;
  for(const auto& resultValtype : functype.parameterType.valtypeVector) {
    resultText << "\n ( result " + resultValtype.getAsText() + ")";
  }
  return resultText.str();
}

} // namespace antiwasm