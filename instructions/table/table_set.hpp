#ifndef ANTIWASM_TABLE_SET_HPP
#define ANTIWASM_TABLE_SET_HPP

namespace antiwasm {
class TableSet : public Instruction {
  uint32_t tableidx;

public:
  explicit TableSet(const uint8_t *instructionContent);
  virtual ~TableSet() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_SET_HPP
