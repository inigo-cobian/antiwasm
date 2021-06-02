#ifndef ANTIWASM_DATA_HPP
#define ANTIWASM_DATA_HPP

#include "bytevec.hpp"
#include "contentBlock.hpp"
#include "expression.hpp"
#include "globaltype.hpp"
#include <cstdint>

enum data_type : uint8_t { modeActive_mem0 = 0x00, modePassive = 0x01, modeActive_memX = 0x02, error_data_type = 0xFF };

namespace antiwasm {
struct Data : public ContentBlock {
  data_type dataType;
  uint32_t memidx{};
  Expression expr{};
  ByteVec bytes{};

  Data(Expression expr_, ByteVec bytes_);
  explicit Data(ByteVec bytes_);
  Data(uint32_t memidx_, Expression expr_, ByteVec bytes_);
  Data() = default;
  [[nodiscard]] std::string getAsText() const;
};

/**
 * Parses and generates the parsed Data.
 * Adds error if cannot complete the parsing.
 * @param dataContent
 * @return
 */
Data parseData(const uint8_t *dataContent);

} // namespace antiwasm

#endif // ANTIWASM_DATA_HPP
