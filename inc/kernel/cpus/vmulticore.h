#ifndef __KVAR_MULTICORE_H
#define __KVAR_MULTICORE_H

#include "kernel/def/typedef.h"

/* 
** In multicore system number of variables must be duplicated by the number of CPUS
** So, automate it :)
*/

/*
** Two using choices:
**   - Declare variable with the prefix and assuming that you know in wich system you are
**   - Using macro init/get/set with the KCONFIG_MAXCPUS define allow you to use it everywhere 
*/

#if KCONFIG_MAXCPUS
    /* The only function which must be provide */
    int cpuGetId(void);

    typedef bool mltcr_bool_t[KCONFIG_MAXCPUS];

    typedef uchar       mltcr_uchar_t[KCONFIG_MAXCPUS];
    typedef ushort      mltcr_ushort_t[KCONFIG_MAXCPUS];
    typedef uint        mltcr_uint_t[KCONFIG_MAXCPUS];
    typedef ulong       mltcr_ulong_t[KCONFIG_MAXCPUS];

    typedef int8        mltcr_int8_t[KCONFIG_MAXCPUS];
    typedef int16       mltcr_int16_t[KCONFIG_MAXCPUS];
    typedef int32       mltcr_int32_t[KCONFIG_MAXCPUS];
    typedef int64       mltcr_int64_t[KCONFIG_MAXCPUS];
    typedef intptr      mltcr_intptr_t[KCONFIG_MAXCPUS];
    typedef ssize_t     mltcr_ssize_t[KCONFIG_MAXCPUS];

    typedef uint8       mltcr_uint8_t[KCONFIG_MAXCPUS];
    typedef uint16      mltcr_uint16_t[KCONFIG_MAXCPUS];
    typedef uint32      mltcr_uint32_t[KCONFIG_MAXCPUS];
    typedef uint64      mltcr_uint64_t[KCONFIG_MAXCPUS];
    typedef uintptr     mltcr_uintptr_t[KCONFIG_MAXCPUS];

    typedef s8_t        mltcr_s8_t[KCONFIG_MAXCPUS];
    typedef s16_t       mltcr_s16_t[KCONFIG_MAXCPUS];
    typedef s32_t       mltcr_s32_t[KCONFIG_MAXCPUS];
    typedef s64_t       mltcr_s64_t[KCONFIG_MAXCPUS];

    typedef u8_t        mltcr_u8_t[KCONFIG_MAXCPUS];
    typedef u16_t       mltcr_u16_t[KCONFIG_MAXCPUS];
    typedef u32_t       mltcr_u32_t[KCONFIG_MAXCPUS];
    typedef u64_t       mltcr_u64_t[KCONFIG_MAXCPUS];

    typedef virtaddr_t  mltcr_virtaddr_t[KCONFIG_MAXCPUS];
    typedef physaddr_t  mltcr_physaddr_t[KCONFIG_MAXCPUS];

    typedef char *      mltcr_chx_t[KCONFIG_MAXCPUS];
    typedef char **     mltcr_chxx_t[KCONFIG_MAXCPUS];

    #define MLTCR_INITXARR(type, x, sz) type x[KCONFIG_MAXCPUS][sz];
    #define MLTCR_INITX(type, x) type x[KCONFIG_MAXCPUS];
    #define MLTCR_VINITX(type, x, y) type x[KCONFIG_MAXCPUS] = {y};

    #define MLTCR_SET(x, y) x[cpuGetId()] = y
    #define MLTCR_GET(x)    x[cpuGetId()]
#else
    typedef bool mltcr_bool_t;

    typedef uchar       mltcr_uchar_t;
    typedef ushort      mltcr_ushort_t;
    typedef uint        mltcr_uint_t;
    typedef ulong       mltcr_ulong_t;

    typedef int8        mltcr_int8_t;
    typedef int16       mltcr_int16_t;
    typedef int32       mltcr_int32_t;
    typedef int64       mltcr_int64_t;
    typedef intptr      mltcr_intptr_t;
    typedef ssize_t     mltcr_ssize_t;

    typedef uint8       mltcr_uint8_t;
    typedef uint16      mltcr_uint16_t;
    typedef uint32      mltcr_uint32_t;
    typedef uint64      mltcr_uint64_t;
    typedef uintptr     mltcr_uintptr_t;

    typedef s8_t        mltcr_s8_t;
    typedef s16_t       mltcr_s16_t;
    typedef s32_t       mltcr_s32_t;
    typedef s64_t       mltcr_s64_t;

    typedef u8_t        mltcr_u8_t;
    typedef u16_t       mltcr_u16_t;
    typedef u32_t       mltcr_u32_t;
    typedef u64_t       mltcr_u64_t;

    typedef virtaddr_t  mltcr_virtaddr_t;
    typedef physaddr_t  mltcr_physaddr_t;

    typedef char *      mltcr_chx_t;
    typedef char **     mltcr_chxx_t;

    #define MLTCR_INITXARR(type, x, sz) type x[sz];
    #define MLTCR_INITX(type, x) type x;
    #define MLTCR_VINITX(type, x, y) type x = y;

    #define MLTCR_SET(x, y) x = y
    #define MLTCR_GET(x)    x
#endif

#define MLTCR_INIT_BOL(x) mltcr_bool_t x
#define MLTCR_INIT_S8(x)  mltcr_s8_t   x
#define MLTCR_INIT_S16(x) mltcr_s16_t  x
#define MLTCR_INIT_S32(x) mltcr_s32_t  x
#define MLTCR_INIT_S64(x) mltcr_s64_t  x
#define MLTCR_INIT_U8(x)  mltcr_u8_t   x
#define MLTCR_INIT_U16(x) mltcr_u16_t  x
#define MLTCR_INIT_U32(x) mltcr_u32_t  x
#define MLTCR_INIT_U64(x) mltcr_u64_t  x

#define MLTCR_INITV_CHX(x, y) mltcr_chx_t  x = { y };
#define MLTCR_INITV_BOL(x, y) mltcr_bool_t x = { y };
#define MLTCR_INITV_S8(x, y)  mltcr_s8_t   x = { y };
#define MLTCR_INITV_S16(x, y) mltcr_s16_t  x = { y };
#define MLTCR_INITV_S32(x, y) mltcr_s32_t  x = { y };
#define MLTCR_INITV_S64(x, y) mltcr_s64_t  x = { y };
#define MLTCR_INITV_U8(x, y)  mltcr_u8_t   x = { y };
#define MLTCR_INITV_U16(x, y) mltcr_u16_t  x = { y };
#define MLTCR_INITV_U32(x, y) mltcr_u32_t  x = { y };
#define MLTCR_INITV_U64(x, y) mltcr_u64_t  x = { y };

#define MLTCR_STATIC_INITV_CHX(x, y) static mltcr_chx_t  x = { y };
#define MLTCR_STATIC_INITV_BOL(x, y) static mltcr_bool_t x = { y };
#define MLTCR_STATIC_INITV_S8(x, y)  static mltcr_s8_t   x = { y };
#define MLTCR_STATIC_INITV_S16(x, y) static mltcr_s16_t  x = { y };
#define MLTCR_STATIC_INITV_S32(x, y) static mltcr_s32_t  x = { y };
#define MLTCR_STATIC_INITV_S64(x, y) static mltcr_s64_t  x = { y };
#define MLTCR_STATIC_INITV_U8(x, y)  static mltcr_u8_t   x = { y };
#define MLTCR_STATIC_INITV_U16(x, y) static mltcr_u16_t  x = { y };
#define MLTCR_STATIC_INITV_U32(x, y) static mltcr_u32_t  x = { y };
#define MLTCR_STATIC_INITV_U64(x, y) static mltcr_u64_t  x = { y };

#define MLTCR_VOLATILE_INITV_CHX(x, y) volatile mltcr_chx_t  x = { y };
#define MLTCR_VOLATILE_INITV_BOL(x, y) volatile mltcr_bool_t x = { y };
#define MLTCR_VOLATILE_INITV_S8(x, y)  volatile mltcr_s8_t   x = { y };
#define MLTCR_VOLATILE_INITV_S16(x, y) volatile mltcr_s16_t  x = { y };
#define MLTCR_VOLATILE_INITV_S32(x, y) volatile mltcr_s32_t  x = { y };
#define MLTCR_VOLATILE_INITV_S64(x, y) volatile mltcr_s64_t  x = { y };
#define MLTCR_VOLATILE_INITV_U8(x, y)  volatile mltcr_u8_t   x = { y };
#define MLTCR_VOLATILE_INITV_U16(x, y) volatile mltcr_u16_t  x = { y };
#define MLTCR_VOLATILE_INITV_U32(x, y) volatile mltcr_u32_t  x = { y };
#define MLTCR_VOLATILE_INITV_U64(x, y) volatile mltcr_u64_t  x = { y };

#endif