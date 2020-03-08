#ifndef _BITFILED_H_
#define _BITFILED_H_

#include "limits.h"
#include "def/typedef.h"

/* BIT OPERATIONS */
/* Usefull functions to clear or set a bit on a bitfield */
static inline uint8 CLEAR_BYTE(uint8 val, uint8 bit)
{
    return (val & (UCHAR_MAX - (1 << bit)));
}

static inline uint8 SET_BYTE(uint8 val, uint8 bit)
{
    return (val | (1 << bit));
}

static inline uint16 CLEAR_WORD(uint16 val, uint8 bit)
{
    return (val & (USHRT_MAX - (1 << bit)));
}

static inline uint16 SET_WORD(uint16 val, uint8 bit)
{
    return (val | (1 << bit));
}

static inline uint32 CLEAR_DOUBLE(uint32 val, uint8 bit)
{
    return (val & (UINT_MAX - (1 << bit)));
}

static inline uint32 SET_DOUBLE(uint32 val, uint8 bit)
{
    return (val | (1 << bit));
}

static inline uint64 CLEAR_QUAD(uint64 val, uint8 bit)
{
    return (val & (ULONG_MAX - (1 << bit)));
}

static inline uint64 SET_QUAD(uint64 val, uint8 bit)
{
    return (val | (1 << bit));
}

#endif
