#ifndef ANTIWASM_F32CONST_HPP
#define ANTIWASM_F32CONST_HPP

#define BOOST_LOG_DYN_LINK 1

#include "float_parser.hpp"
#include "instruction.hpp"
#include <boost/log/trivial.hpp>

namespace antiwasm {
class F32Const : public Instruction {
  float constant;

public:
  explicit F32Const(const uint8_t *instrContent);
  virtual ~F32Const() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F32CONST_HPP
