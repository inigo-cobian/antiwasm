#ifndef ANTIWASM_GLOBAL_HPP
#define ANTIWASM_GLOBAL_HPP

#include "contentBlock.hpp"
#include "globaltype.hpp"
#include "expression.hpp"

namespace antiwasm {
struct Global : public ContentBlock {
  Globaltype globaltype;
  Expression expr;
};

}

#endif // ANTIWASM_GLOBAL_HPP
