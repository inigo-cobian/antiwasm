#ifndef ANTIWASM_CONST_HPP
#define ANTIWASM_CONST_HPP

#include "../includes/instruction.hpp"

class I32Const : public Instruction {
private:
    getI32Const(uint8_t* i32ConstAsBytes);
public:
    Parse(uint8_t* operands) const override { instructionCode_ = instruction_set::i32_const; getI32Const(operands);};
};

#endif //ANTIWASM_CONST_HPP
