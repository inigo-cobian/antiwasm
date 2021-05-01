#include "typesec.hpp"

using namespace std;
namespace antiwasm {

TypeSection::TypeSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::TypeId, size, content, initialPos) {}

TypeSection::~TypeSection() {}

void TypeSection::addFunctype(Functype functype) { functypeVector.push_back(functype); }

vector<Functype> TypeSection::getFunctypeVector() { return functypeVector; }

void TypeSection::displaySectionHeaderInfo() {
  cout << "    Type | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void TypeSection::displaySectionContentInfo() {
  cout << "    Type | start=" << hex << initialPos_ << " size=" << hex << size_ << " (" << functypeVector.size()
       << ") functypes" << endl;

  size_t index = 0;
  for (const auto &functype : functypeVector) {
    stringstream functypeAsText;
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
    cout << functypeAsText.str() << endl;
  }
}

string TypeSection::getParamAsText(const Functype &functype) const {
  stringstream paramText;
  paramText << "\n ( param ";
  for (const auto &paramValtype : functype.parameterType.valtypeVector) {
    paramText << paramValtype.getAsText() << " ";
  }
  paramText << ")";
  return paramText.str();
}

string TypeSection::getResultAsText(const Functype &functype) const {
  stringstream resultText;
  resultText << "\n ( result ";
  for (const auto &resultValtype : functype.returnType.valtypeVector) {
    resultText << resultValtype.getAsText() + " ";
  }
  resultText << ")";
  return resultText.str();
}

} // namespace antiwasm