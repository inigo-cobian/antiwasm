#include "../includes/expression_parser.hpp"

namespace antiwasm {

    void parseInstr(unsigned char *instruction, int &pointer) {
        //TODO create the parsing of instructions
        do {
            if (instruction[pointer++] == 0x0B) {
                BOOST_LOG_TRIVIAL(trace) << "END of instruction";
                return;
            }
        } while (true);
    }

    void parseExpression(uint8_t instruction) {
        switch (instruction) {
            case (instruction_set::i32_const):
                parseConstInt32(Driver::GetInstance()->GetNextBytes(2));
                break;
            case (instruction_set::i64_const):
                parseConstInt64(Driver::GetInstance()->GetNextBytes(4));
                break;
            case (instruction_set::f32_const):
                parseConstFloat32(Driver::GetInstance()->GetNextBytes(2));
                break;
            case (instruction_set::f64_const):
                parseConstFloat64(Driver::GetInstance()->GetNextBytes(4));
                break;
        }
    }

    void parseConstInt32(uint8_t *operands) {
        //TODO
        BOOST_LOG_TRIVIAL(debug) << "Const i32 " << operands[0] << operands[1] << " bytes";
    }

    void parseConstInt64(uint8_t *operands) {
        //TODO
        BOOST_LOG_TRIVIAL(debug) << "Const i64 " << operands[0] << operands[1] << " bytes";
    }

    void parseConstFloat32(uint8_t *operands) {
        //TODO
        BOOST_LOG_TRIVIAL(debug) << "Const f32 " << operands[0] << operands[1] << " bytes";
    }

    void parseConstFloat64(uint8_t *operands) {
        //TODO
        BOOST_LOG_TRIVIAL(debug) << "Const f64 " << operands[0] << operands[1] << " bytes";
    }

}