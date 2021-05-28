#ifndef ANTIWASM_SELECT_VECVALTYPE_HPP
#define ANTIWASM_SELECT_VECVALTYPE_HPP

#include "instruction.hpp"
#include "memarg.hpp"
#include "valtype.hpp"

namespace antiwasm {
class SelectValtypeInstr : public Instruction {
  std::vector<Valtype> valtypeVec;

public:
  explicit SelectValtypeInstr(const uint8_t *instrContent);
  virtual ~SelectValtypeInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_SELECT_VECVALTYPE_HPP
