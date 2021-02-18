#include "../includes/expression_parser.hpp"

namespace antiwasm {

    void parseInstr(const unsigned char *instructionPtr, int &pointer) {
        //TODO create the parsing of instructions
        do {
            if (instructionPtr[pointer++] == 0x0B) {
                BOOST_LOG_TRIVIAL(trace) << "END of instruction";
                return;
            }
        } while (true);
    }

    void parseExpression(uint8_t instructionCode) {
        Instruction* instruction; //TODO store the Instruction somewhere
        switch (instructionCode) {
            case (instruction_set::i32_const):
                instruction = new I32Const(Driver::GetInstance()->GetNextBytes(2));
                break;
            case (instruction_set::i64_const):
                instruction = new I64Const(Driver::GetInstance()->GetNextBytes(4));
                break;
            case (instruction_set::f32_const):
                instruction = new F32Const(Driver::GetInstance()->GetNextBytes(2));
                break;
            case (instruction_set::f64_const):
                instruction = new F64Const(Driver::GetInstance()->GetNextBytes(4));
                break;
            default:
                //TODO when the parsing is completed, print an error message
                break;
        }
    }
}