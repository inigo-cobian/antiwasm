#include "tabletype.hpp"

namespace antiwasm {

Tabletype parseTableType(const uint8_t *tableTypeContent) {
  BOOST_LOG_TRIVIAL(debug) << "[Tabletype] Parsing a new Tabletype";

  BOOST_LOG_TRIVIAL(debug) << "[Tabletype] Parsing a new Reftype for Tabletype";
  Reftype reftypeAtTabletype = parseReftype(tableTypeContent[0]);
  Limit limitAtTabletype = parseLimits(&tableTypeContent[1]);
  Tabletype tabletype{reftypeAtTabletype, limitAtTabletype};

  if (reftypeAtTabletype == invalid_reftype) {
    std::cout << "ErrorId at reftype" << std::endl;
    BOOST_LOG_TRIVIAL(error) << "[Resulttype] Incorrect Reftype with value: " << tableTypeContent[0];
    auto error = generateError(fatal, unrecognizedReftypeAtTabletype, 0);
    tabletype.addError(error);
    return tabletype;
  }

  if (limitAtTabletype.hasError()) {
    std::cout << "ErrorId at limit" << std::endl;
    BOOST_LOG_TRIVIAL(error) << "[Resulttype] Incorrect Limit";
    auto error = generateError(fatal, unrecognizedLimitHeaderAtTabletype, 1);
    tabletype.addError(error);
  }

  if (!tabletype.hasError()) {
    tabletype.setNBytes(REFTYPE_SIZE + limitAtTabletype.getNBytes());
    BOOST_LOG_TRIVIAL(error) << "[Resulttype] nBytes: " << tabletype.getNBytes();
  }

  return tabletype;
}
std::string Tabletype::getAsText() const {
  std::stringstream tabletypeAsText;
  tabletypeAsText << "( table $index"
                  << " "; // TODO ¿index?
  if (limit.type == limit_min) {
    tabletypeAsText << limit.min;
  } else if (limit.type == limit_min_max) {
    tabletypeAsText << limit.min << " " << limit.max;
  }
  tabletypeAsText << " " << getReftypeAsText(reftype) << " )\n";
  return tabletypeAsText.str();
}
} // namespace antiwasm
