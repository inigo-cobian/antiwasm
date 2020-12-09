#ifndef ANTIWASM_CONST_HPP
#define ANTIWASM_CONST_HPP

#include "../includes/instruction.hpp"
#include <cstdint>

class I32Const : public virtual Instruction {
private:
    int32_t getI32Const(uint8_t* i32ConstAsBytes);
    int32_t value = 0;
public:
    I32Const(uint8_t* operands) { instructionCode_ = instruction_set::i32_const; getI32Const(operands); };
};

class I64Const : public virtual Instruction {
private:
    int64_t getI64Const(uint8_t* i64ConstAsBytes);
    int64_t value = 0;
public:
    I64Const(uint8_t* operands) { instructionCode_ = instruction_set::i64_const; getI64Const(operands); };
};

class F32Const : public virtual Instruction {
private:
    float getF32Const(uint8_t* f32ConstAsBytes);
    float value = 0;
public:
    F32Const(uint8_t* operands) { instructionCode_ = instruction_set::f32_const; getF32Const(operands); };
};

class F64Const : public virtual Instruction {
private:
    double getF64Const(uint8_t* f64ConstAsBytes);
    double value = 0;
public:
    F64Const(uint8_t* operands) { instructionCode_ = instruction_set::f64_const; getF64Const(operands); };
};

#endif //ANTIWASM_CONST_HPP
