#ifndef ANTIWASM_INSTRUCTION_HPP
#define ANTIWASM_INSTRUCTION_HPP

#include <cstdint>
#include "../includes/lexems.hpp"

class Instruction {
protected:
    instruction_set instructionCode_;
public:
    virtual Instruction() {}
    virtual ~Instruction() {}
    virtual Parse(uint8_t* operands);
    virtual instruction_set getInstructionCode();
};

#endif //ANTIWASM_INSTRUCTION_HPP
