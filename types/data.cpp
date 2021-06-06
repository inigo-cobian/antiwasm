#include "data.hpp"

namespace antiwasm {
std::string Data::getAsText() const {
  std::stringstream dataAsText;

  dataAsText << "( data ";

  switch (dataType) {
  case modeActive_mem0:
    dataAsText << "mem0 "; // TODO << expr.getAsText();
    break;
  case modePassive:
    dataAsText << "passive ";
    break;
  case modeActive_memX:
    dataAsText << "mem" << std::hex << memidx << " "; // TODO << expr.getAsText();
    break;
  case error_data_type:
    dataAsText << "error )\n";
    return dataAsText.str();
  }

  dataAsText << bytes.getAsText() << "\n)";

  return dataAsText.str();
}

Data::Data(Expression expr_, ByteVec bytes_) : dataType(modeActive_mem0), expr(std::move(expr_)), bytes(bytes_) {}

Data::Data(ByteVec bytes_) : dataType(modePassive), bytes(bytes_) {}

Data::Data(uint32_t memidx_, Expression expr_, ByteVec bytes_)
    : dataType(modeActive_memX), memidx(memidx_), expr(std::move(expr_)), bytes(bytes_) {}

Data parseData(const uint8_t *dataContent) {
  if (dataContent[0] == modeActive_mem0) {
    BOOST_LOG_TRIVIAL(debug) << "[data] Creating a Data of type 0x00";

    Expression expr = parseExpression(dataContent + 1);
    if (expr.hasError()) {
      Data data{};
      data.dataType = modeActive_mem0;
      auto error = generateError(fatal, invalidExpressionAtData, 0);
      data.addError(error);
      return data;
    }

    auto pos = expr.getNBytes() + 1;
    ByteVec byteVec(dataContent + pos);

    Data data{expr, byteVec};
    return data;
  }

  if (dataContent[0] == modePassive) {
    BOOST_LOG_TRIVIAL(debug) << "[data] Creating a Data of type 0x01";

    ByteVec byteVec(dataContent + 1);
    Data data{byteVec};
    return data;
  }

  if (dataContent[0] == modeActive_memX) {
    BOOST_LOG_TRIVIAL(debug) << "[data] Creating a Data of type 0x02";

    uint32_t memidx = transformLeb128ToUnsignedInt32(dataContent + 1);
    size_t pos = sizeOfLeb128(dataContent + 1) + 1;

    Expression expr = parseExpression(dataContent + pos);
    if (expr.hasError()) {
      Data data{};
      data.dataType = modeActive_memX;
      auto error = generateError(fatal, invalidExpressionAtData, 0);
      data.addError(error);
      return data;
    }

    pos += expr.getNBytes();
    ByteVec byteVec(dataContent + pos);
    Data data{memidx, expr, byteVec};
    return data;
  }

  // Error case
  BOOST_LOG_TRIVIAL(debug) << "[data] Error: found a Data with unknown type " << std::hex << dataContent[0];
  Data data{};
  data.dataType = error_data_type;
  auto error = generateError(fatal, unrecognizedDataHeader, 0);
  data.addError(error);
  return data;
}

} // namespace antiwasm