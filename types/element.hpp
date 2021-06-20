#ifndef ANTIWASM_ELEMENT_HPP
#define ANTIWASM_ELEMENT_HPP

#include "contentBlock.hpp"
#include "expression.hpp"
#include <sstream>
#include <utility>
#include <vector>

namespace antiwasm {

enum Elemkind : uint8_t { funcrefElemkind = 0x00, invalidElemkind = 0xAA };

enum ElemHeader : uint8_t {
  elem0 = 0x00,
  elem1 = 0x01,
  elem2 = 0x02,
  elem3 = 0x03,
  elem4 = 0x04,
  elem5 = 0x05,
  elem6 = 0x06,
  elem7 = 0x07,
  invalid_elem = 0xAA
};

struct Element : public ContentBlock {
  ElemHeader elemHeader{};
  Expression expr;
  std::vector<uint32_t> funcidxVec;
  Elemkind elemkind;
  uint32_t tableidx;
  std::vector<Expression> expressionVec;
  Reftype reftype;

  Element(); // Default for error cases
  Element(ElemHeader elemHeader_);

  Element(Expression expr_, std::vector<uint32_t> funcidxVec_);
  Element(ElemHeader elemHeader_, Elemkind elemkind_, std::vector<uint32_t> funcidxVec_); // same for 0x00 & 0x03
  Element(uint32_t tableidx_, Expression expr_, Elemkind elemkind_, std::vector<uint32_t> funcidxVec_);
  Element(Expression expr_, std::vector<Expression> expressionVec_);
  Element(ElemHeader elemHeader_, Reftype reftype_, std::vector<Expression> expressionVec_); // same for 0x05 & 0x07
  Element(uint32_t tableidx_, Expression expr_, Reftype reftype_, std::vector<Expression> expressionVec_);

  [[nodiscard]] std::string getAsText(size_t index) const;
};

/**
 * Parses and generates the parsed Element.
 * Adds error if cannot complete the parsing.
 * @param elementContent
 * @return
 */
Element parseElement(const uint8_t *elementContent);

/**
 * Gets the value of ElemHeader from the byte.
 * If the byte does not correspond to any existing value, returns invalid_elem.
 * @param elemHeader
 * @return
 */
ElemHeader parseElemHeader(uint8_t elemHeaderValue);

/**
 * Gets the value of Elemkind from the byte.
 * If the byte does not correspond to any existing value, returns invalidElemkind.
 * @param elemKindValue
 * @return
 */
Elemkind parseElemkind(uint8_t elemKindValue);

} // namespace antiwasm

#endif // ANTIWASM_ELEMENT_HPP
