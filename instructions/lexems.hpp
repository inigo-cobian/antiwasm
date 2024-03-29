#ifndef LEXEMS_HPP
#define LEXEMS_HPP

#include <cstdint>

enum InstructionSet : uint8_t {
  Unreachable = 0x00,
  Nop = 0x01,
  Block = 0x02,
  Loop = 0x03,
  If = 0x04,
  Else = 0x05,
  End = 0x0B,
  Br = 0x0C,
  Br_if = 0x0D,
  Br_table = 0x0E,
  Return = 0x0F,
  Call = 0x10,
  Call_indirect = 0x11,
  Drop = 0x1A,
  Select = 0x1B,
  Select_vecValtype = 0x1C,

  Local_get = 0x20,
  Local_set = 0x21,
  Local_tee = 0x22,
  Global_get = 0x23,
  Global_set = 0x24,

  Table_get = 0x25,
  Table_set = 0x26,

  i32_load = 0x28,
  i64_load = 0x29,
  f32_load = 0x2A,
  f64_load = 0x2B,

  i32_load8_s = 0x2C,
  i32_load8_u = 0x2D,
  i32_load16_s = 0x2E,
  i32_load16_u = 0x2F,

  i64_load8_s = 0x30,
  i64_load8_u = 0x31,
  i64_load16_s = 0x32,
  i64_load16_u = 0x33,
  i64_load32_s = 0x34,
  i64_load32_u = 0x35,

  i32_store = 0x36,
  i64_store = 0x37,
  f32_store = 0x38,
  f64_store = 0x39,

  i32_store8 = 0x3A,
  i32_store16 = 0x3B,
  i64_store8 = 0x3C,
  i64_store16 = 0x3D,
  i64_store32 = 0x3E,

  Memory_size = 0x3F,
  Memory_grow = 0x40,

  i32_const = 0x41,
  i64_const = 0x42,
  f32_const = 0x43,
  f64_const = 0x44,

  i32_eqz = 0x45,
  i32_eq = 0x46,
  i32_ne = 0x47,
  i32_lt_s = 0x48,
  i32_lt_u = 0x49,
  i32_gt_s = 0x4A,
  i32_gt_u = 0x4B,
  i32_le_s = 0x4C,
  i32_le_u = 0x4D,
  i32_ge_s = 0x4E,
  i32_ge_u = 0x4F,

  i64_eqz = 0x50,
  i64_eq = 0x51,
  i64_ne = 0x52,
  i64_lt_s = 0x53,
  i64_lt_u = 0x54,
  i64_gt_s = 0x55,
  i64_gt_u = 0x56,
  i64_le_s = 0x57,
  i64_le_u = 0x58,
  i64_ge_s = 0x59,
  i64_ge_u = 0x5A,

  f32_eq = 0x5B,
  f32_ne = 0x5C,
  f32_lt = 0x5D,
  f32_gt = 0x5E,
  f32_le = 0x5F,
  f32_ge = 0x60,

  f64_eq = 0x61,
  f64_ne = 0x62,
  f64_lt = 0x63,
  f64_gt = 0x64,
  f64_le = 0x65,
  f64_ge = 0x66,

  i32_clz = 0x67,
  i32_ctz = 0x68,
  i32_popcnt = 0x69,

  i32_add = 0x6A,
  i32_sub = 0x6B,
  i32_mul = 0x6C,

  i32_div_s = 0x6D,
  i32_div_u = 0x6E,
  i32_rem_s = 0x6F,
  i32_rem_u = 0x70,

  i32_and = 0x71,
  i32_or = 0x72,
  i32_xor = 0x73,

  i32_shl = 0x74,
  i32_shr_s = 0x75,
  i32_shr_u = 0x76,
  i32_rotl = 0x77,
  i32_rotr = 0x78,

  i64_clz = 0x79,
  i64_ctz = 0x7A,
  i64_popcnt = 0x7B,

  i64_add = 0x7C,
  i64_sub = 0x7D,
  i64_mul = 0x7E,

  i64_div_s = 0x7F,
  i64_div_u = 0x80,
  i64_rem_s = 0x81,
  i64_rem_u = 0x82,

  i64_and = 0x83,
  i64_or = 0x84,
  i64_xor = 0x85,

  i64_shl = 0x86,
  i64_shr_s = 0x87,
  i64_shr_u = 0x88,
  i64_rotl = 0x89,
  i64_rotr = 0x8A,

  f32_abs = 0x8B,
  f32_neg = 0x8C,
  f32_ceil = 0x8D,
  f32_floor = 0x8E,
  f32_trunc = 0x8F,
  f32_nearest = 0x90,
  f32_sqrt = 0x91,
  f32_add = 0x92,
  f32_sub = 0x93,
  f32_mul = 0x94,
  f32_div = 0x95,
  f32_min = 0x96,
  f32_max = 0x97,
  f32_copysign = 0x98,

  f64_abs = 0x99,
  f64_neg = 0x9A,
  f64_ceil = 0x9B,
  f64_floor = 0x9C,
  f64_trunc = 0x9D,
  f64_nearest = 0x9E,
  f64_sqrt = 0x9F,
  f64_add = 0xA0,
  f64_sub = 0xA1,
  f64_mul = 0xA2,
  f64_div = 0xA3,
  f64_min = 0xA4,
  f64_max = 0xA5,
  f64_copysign = 0xA6,

  i32_wrap_i64 = 0xA7,
  i32_trunc_f32_s = 0xA8,
  i32_trunc_f32_u = 0xA9,
  i32_trunc_f64_s = 0xAA,
  i32_trunc_f64_u = 0xAB,

  i64_extend_i32_s = 0xAC,
  i64_extend_i32_u = 0xAD,

  i64_trunc_f32_s = 0xAE,
  i64_trunc_f32_u = 0xAF,
  i64_trunc_f64_s = 0xB0,
  i64_trunc_f64_u = 0xB1,

  f32_convert_i32_s = 0xB2,
  f32_convert_i32_u = 0xB3,
  f32_convert_i64_s = 0xB4,
  f32_convert_i64_u = 0xB5,

  f32_demote_f64 = 0xB6,

  f64_convert_i32_s = 0xB7,
  f64_convert_i32_u = 0xB8,
  f64_convert_i64_s = 0xB9,
  f64_convert_i64_u = 0xBA,

  f64_promote_f32 = 0xBB,

  i32_reinterpret_f32 = 0xBC,
  i64_reinterpret_f64 = 0xBD,
  f32_reinterpret_i32 = 0xBE,
  f64_reinterpret_i64 = 0xBF,

  i32_extend8_s = 0xC0,
  i32_extend16_s = 0xC1,
  i64_extend8_s = 0xC2,
  i64_extend16_s = 0xC3,
  i64_extend32_s = 0xC4,

  Ref_null = 0xD0,
  Ref_is_null = 0xD1,
  Ref_func = 0xD2,

  double_byte_instr = 0xFC,

  error_instr = 0xFF // returned if there is no instr with this code
};

enum SecondByteSet : uint8_t {
  i32_trunc_sat_f32_s = 0x00,
  i32_trunc_sat_f32_u = 0x01,
  i32_trunc_sat_f64_s = 0x02,
  i32_trunc_sat_f64_u = 0x03,
  i64_trunc_sat_f32_s = 0x04,
  i64_trunc_sat_f32_u = 0x05,
  i64_trunc_sat_f64_s = 0x06,
  i64_trunc_sat_f64_u = 0x07,

  Memory_init = 0x08,
  Data_drop = 0x09,
  Memory_copy = 0x0A,
  Memory_fill = 0x0B,
  Table_init = 0x0C,
  Elem_drop = 0x0D,
  Table_copy = 0x0E,
  Table_grow = 0x0F,
  Table_size = 0x10,
  Table_fill = 0x11
};

#endif
