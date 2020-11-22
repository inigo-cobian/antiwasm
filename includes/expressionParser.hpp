#ifndef ANTIWASM_EXPRESSION_PARSER_HPP
#define ANTIWASM_EXPRESSION_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <boost/log/trivial.hpp>
#include <cstdint>
#include "../includes/driver.hpp"
#include "../includes/lexems.hpp"

namespace antiwasm {
    void parseInstr(unsigned char *instruction, int &pointer);
    void parseExpression(uint8_t instruction);

    void parseConstInt32(uint8_t *operands);
    void parseConstInt64(uint8_t *operands);
    void parseConstFloat32(uint8_t *operands);
    void parseConstFloat64(uint8_t *operands);
}

#endif //ANTIWASM_EXPRESSION_PARSER_HPP
