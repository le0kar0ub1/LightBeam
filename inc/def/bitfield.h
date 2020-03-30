#ifndef _BITFILED_H_
#define _BITFILED_H_

#include "limits.h"
#include "def/typedef.h"

/* BIT OPERATIONS */
/* Usefull functions to clear or set a bit on a bitfield */
static inline u8_t CLEAR_BYTE(u8_t val, u8_t bit)
{
    return (val & (UCHAR_MAX - (1 << bit)));
}

static inline u8_t SET_BYTE(u8_t val, u8_t bit)
{
    return (val | (1 << bit));
}

static inline u16_t CLEAR_WORD(u16_t val, u8_t bit)
{
    return (val & (USHRT_MAX - (1 << bit)));
}

static inline u16_t SET_WORD(u16_t val, u8_t bit)
{
    return (val | (1 << bit));
}

static inline u32_t CLEAR_DOUBLE(u32_t val, u8_t bit)
{
    return (val & (UINT_MAX - (1 << bit)));
}

static inline u32_t SET_DOUBLE(u32_t val, u8_t bit)
{
    return (val | (1 << bit));
}

static inline u64_t CLEAR_QUAD(u64_t val, u8_t bit)
{
    return (val & (ULONG_MAX - (1 << bit)));
}

static inline u64_t SET_QUAD(u64_t val, u8_t bit)
{
    return (val | (1 << bit));
}

#endif
