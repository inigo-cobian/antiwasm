#include "element.hpp"

#include <utility>

namespace antiwasm {

Element::Element() : elemHeader(invalid_elem) {
  addError(generateError(fatal, invalidHeaderAtElement, 0));
}

Element::Element(ElemHeader elemHeader_) : elemHeader(elemHeader_) {
  addError(generateError(fatal, invalidElemkindAtElement, 0));
}

Element::Element(Expression expr_, std::vector<uint32_t> funcidxVec_)
    : elemHeader(elem0), expr(std::move(expr_)), funcidxVec(std::move(funcidxVec_)) {}

Element::Element(ElemHeader elemHeader_, Elemkind elemkind_, std::vector<uint32_t> funcidxVec_)
    : elemHeader(elemHeader_), elemkind(elemkind_), funcidxVec(std::move(funcidxVec_)) {}

Element::Element(uint32_t tableidx_, Expression expr_, Elemkind elemkind_, std::vector<uint32_t> funcidxVec_)
    : elemHeader(elem2), tableidx(tableidx_), expr(std::move(expr_)), elemkind(elemkind_), funcidxVec(std::move(funcidxVec_)) {}

Element::Element(Expression expr_, std::vector<Expression> expressionVec_)
    : elemHeader(elem4), expr(std::move(expr_)), expressionVec(std::move(expressionVec_)) {}

Element::Element(ElemHeader elemHeader_, Reftype reftype_, std::vector<Expression> expressionVec_)
    : elemHeader(elemHeader_), reftype(reftype_), expressionVec(std::move(expressionVec_)) {}

Element::Element(uint32_t tableidx_, Expression expr_, Reftype reftype_, std::vector<Expression> expressionVec_)
    : elemHeader(elem6), tableidx(tableidx_), expr(std::move(expr_)), reftype(reftype_), expressionVec(std::move(expressionVec_)) {}

Element parseElement(const uint8_t *elementContent) {
  ElemHeader elemHeader = parseElemHeader(elementContent[0]);

  if(elemHeader == invalid_elem) {
    return Element{};
  }
  size_t pos = 1;

  switch(elemHeader) {
  case elem0: {
    auto expr = parseExpression(elementContent + pos);
    pos += expr.getNBytes();

    auto sizeVecFuncidx = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);
    std::vector<uint32_t> funcidxVec;
    for (size_t i = 0; i < sizeVecFuncidx; i++) {
      auto funcidx = transformLeb128ToUnsignedInt32(elementContent + pos);
      pos += sizeOfLeb128(elementContent + pos);
      funcidxVec.push_back(funcidx);
    }
    Element element{expr, funcidxVec};
    element.addNBytes(pos);
    return element;
  }
  case elem1:
  case elem3: {
    Elemkind elemkind = parseElemkind(elementContent[pos]);
    pos++;
    if (elemkind == Elemkind::invalidElemkind) {
      return Element{elemHeader};
    }

    auto sizeVecFuncidx = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);
    std::vector<uint32_t> funcidxVec;
    for (size_t i = 0; i < sizeVecFuncidx; i++) {
      auto funcidx = transformLeb128ToUnsignedInt32(elementContent + pos);
      pos += sizeOfLeb128(elementContent + pos);
      funcidxVec.push_back(funcidx);
    }

    Element element{elemHeader, elemkind, funcidxVec};
    element.addNBytes(pos);
    return element;
  }
  case elem2: {
    uint32_t tableidx = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);

    auto expr = parseExpression(elementContent + pos);
    pos += expr.getNBytes();

    Elemkind elemkind = parseElemkind(elementContent[pos]);
    pos++;
    if (elemkind == Elemkind::invalidElemkind) {
      return Element{elemHeader};
    }

    auto sizeVecFuncidx = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);
    std::vector<uint32_t> funcidxVec;
    for (size_t i = 0; i < sizeVecFuncidx; i++) {
      auto funcidx = transformLeb128ToUnsignedInt32(elementContent + pos);
      pos += sizeOfLeb128(elementContent + pos);
      funcidxVec.push_back(funcidx);
    }
    Element element{tableidx, expr, elemkind, funcidxVec};
    element.addNBytes(pos);
    return element;
  }
  case elem4: {
    auto expr = parseExpression(elementContent + pos);
    pos += expr.getNBytes();

    size_t sizeVecExpr = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);
    std::vector<Expression> exprVec;
    for(size_t i = 0; i < sizeVecExpr; i++) {
      auto exprOfvec = parseExpression(elementContent + pos);
      pos += exprOfvec.getNBytes();
      exprVec.push_back(exprOfvec);
    }
    Element element{expr, exprVec};
    element.addNBytes(pos);
    return element;
  }
  case elem5:
  case elem7: {
    auto reftype = parseReftype(elementContent[pos]);
    pos++;

    size_t sizeVecExpr = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);
    std::vector<Expression> exprVec;
    for(size_t i = 0; i < sizeVecExpr; i++) {
      auto exprOfvec = parseExpression(elementContent + pos);
      pos += exprOfvec.getNBytes();
      exprVec.push_back(exprOfvec);
    }
    Element element{elemHeader, reftype, exprVec};
    element.addNBytes(pos);
    return element;
  }
  case elem6: {
    uint32_t tableidx = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);

    auto expr = parseExpression(elementContent + pos);
    pos += expr.getNBytes();

    auto reftype = parseReftype(elementContent[pos]);
    pos++;

    size_t sizeVecExpr = transformLeb128ToUnsignedInt32(elementContent + pos);
    pos += sizeOfLeb128(elementContent + pos);
    std::vector<Expression> exprVec;
    for(size_t i = 0; i < sizeVecExpr; i++) {
      auto exprOfvec = parseExpression(elementContent + pos);
      pos += exprOfvec.getNBytes();
      exprVec.push_back(exprOfvec);
    }
    Element element{tableidx, expr, reftype, exprVec};
    element.addNBytes(pos);
    return element;
  }
  }
}

ElemHeader parseElemHeader(const uint8_t elemHeaderValue) {
  if (elemHeaderValue >= 0x00 && elemHeaderValue <= 0x07) {
    return (ElemHeader)elemHeaderValue;
  }
  return invalid_elem;
}

Elemkind parseElemkind(const uint8_t elemKindValue) {
  if (elemKindValue == 0x00) {
    return (Elemkind)elemKindValue;
  }
  return invalidElemkind;
}

} // namespace antiwasm