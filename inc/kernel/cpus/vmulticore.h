#ifndef __KVAR_MULTICORE_H
#define __KVAR_MULTICORE_H

#include "kernel/def/typedef.h"

int cpuGetId(void);

/* 
** In multicore system number of variables must be duplicated
** So, automate it :)
*/

#if KCONFIG_MAXCPUS
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

    #define MLCTR_INIT_BOL(x) (mltcr_bool_t #x)
    #define MLCTR_INIT_S8(x)  (mltcr_s8_t   #x)
    #define MLCTR_INIT_S16(x) (mltcr_s16_t  #x)
    #define MLCTR_INIT_S32(x) (mltcr_s32_t  #x)
    #define MLCTR_INIT_S64(x) (mltcr_s64_t  #x)
    #define MLCTR_INIT_U8(x)  (mltcr_u8_t   #x)
    #define MLCTR_INIT_U16(x) (mltcr_u16_t  #x)
    #define MLCTR_INIT_U32(x) (mltcr_u32_t  #x)
    #define MLCTR_INIT_U64(x) (mltcr_u64_t  #x)

    #define MLCTR_INITV_BOL(x, y) (mltcr_bool_t #x = y)
    #define MLCTR_INITV_S8(x, y)  (mltcr_s8_t   #x = y)
    #define MLCTR_INITV_S16(x, y) (mltcr_s16_t  #x = y)
    #define MLCTR_INITV_S32(x, y) (mltcr_s32_t  #x = y)
    #define MLCTR_INITV_S64(x, y) (mltcr_s64_t  #x = y)
    #define MLCTR_INITV_U8(x, y)  (mltcr_u8_t   #x = y)
    #define MLCTR_INITV_U16(x, y) (mltcr_u16_t  #x = y)
    #define MLCTR_INITV_U32(x, y) (mltcr_u32_t  #x = y)
    #define MLCTR_INITV_U64(x, y) (mltcr_u64_t  #x = y)

    #define MLCTR_SET(x, y) (x[cpuGetId()] = y)
    #define MLCTR_ZER(x)    (x[cpuGetId()] = 0)
    #define MLCTR_GET(x)    (x[cpuGetId()])
#endif

#endif