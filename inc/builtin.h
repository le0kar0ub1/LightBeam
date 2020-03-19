#ifndef _BUILTIN_H_
#define _BUILTIN_H_

/* PREPROCESSOR */
// #pragma GCC
/* warning | error | diagnostic | ... + "message" */
// #pragma message ""
// #pragma once
// #pragma startup set() // call before main
// #pragma exit unset()  // call after main

/* STANDARD HEADERS */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/* PERSONNAL HEADERS */
#include "def/macro.h"
#include "def/typedef.h"
#include "def/keyword.h"
#include "def/bitfield.h"
#include "def/assert.h"
#include "def/operator.h"

#endif
