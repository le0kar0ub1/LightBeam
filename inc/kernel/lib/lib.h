#ifndef __OVERWORLD_H_
#define __OVERWORLD_H_

#include "kernel/def/typedef.h"
#include <stdbool.h>
#include <stdarg.h>
#include "kernel/lib/printf.h"

u32_t strlen(char const *);

/* Number instrument */
u32_t numberlen(u32_t, u8_t);

/* Memory instrument */
void *memcpy(void *, const void *, size_t);
void *memcpyv(void *, const void *, size_t, u8_t);
bool memcmp(const void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memsetw(void *x, int, size_t);
void *memsetd(void *x, int, size_t);
void *memsetq(void *x, int, size_t);

/* String instrument */
bool strcmp(char const *, char const *);
bool strncmp(char const *, char const *, size_t);

/* Str to Nbr */
u8_t fromPrefixToBase(char const **);
s32_t atoi(char const *);
s32_t atoib(char const *, u8_t);
s64_t atol(char const *);
s64_t atolb(char const *, u8_t);

#endif