#ifndef ANTIWASM_INSTRUCTION_HPP
#define ANTIWASM_INSTRUCTION_HPP

#include <cstdint>
#include "../includes/lexems.hpp"

class Instruction {
protected:
    instruction_set instructionCode_;
public:
    virtual ~Instruction() {}
    instruction_set getInstructionCode() { return instructionCode_; };
};

#endif //ANTIWASM_INSTRUCTION_HPP
