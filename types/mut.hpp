#ifndef ANTIWASM_MUT_HPP
#define ANTIWASM_MUT_HPP

enum Mut : int32_t {
    const_ = 0x00,
    var_ = 0x01,
    invalid_mut = 0xAA
};

namespace antiwasm {
    Mut parseMut(const unsigned char mutContent);
}

#endif //ANTIWASM_MUT_HPP
