#ifndef VAL_TYPE_HPP
#define VAL_TYPE_HPP

namespace antiwasm {
    inline enum ValType
    {
        i32 = 0x7F,
        i64 = 0x7E,
        f32 = 0x7D,
        f64 = 0x7C
    }ValType;
}

#endif
