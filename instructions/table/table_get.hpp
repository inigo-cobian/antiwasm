#ifndef ANTIWASM_TABLE_GET_HPP
#define ANTIWASM_TABLE_GET_HPP

namespace antiwasm {
class TableGet : public Instruction {
  uint32_t tableidx;

public:
  explicit TableGet(const uint8_t *instructionContent);
  virtual ~TableGet() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TABLE_GET_HPP
