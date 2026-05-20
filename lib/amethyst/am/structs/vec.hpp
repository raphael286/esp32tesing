#ifndef AMETHYST_VEC_H
#define AMETHYST_VEC_H

#include "stdint.h"

typedef struct {
    uint8_t x;
    uint8_t y;
} vec2_u8_t;

typedef struct {
    uint16_t x;
    uint16_t y;
} vec2_u16_t;

typedef struct {
    uint32_t x;
    uint32_t y;
} vec2_u32_t;

typedef struct {
    uint64_t x;
    uint64_t y;
} vec2_u64_t;

#endif