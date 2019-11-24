#ifndef BASETYPES_H
#define BASETYPES_H

#ifdef _WIN32
#pragma once
#endif

#include "osconfig.h"
#include "commonmacros.h"

#include "mathlib.h"

// For backward compatibilty only...
#include "tier0/platform.h"

// stdio.h
#ifndef NULL
#define NULL 0
#endif

// Pad a number so it lies on an N byte boundary.
// So PAD_NUMBER(0,4) is 0 and PAD_NUMBER(1,4) is 4
#define PAD_NUMBER(number, boundary) \
	(((number) + ((boundary) - 1)) / (boundary)) * (boundary)

#ifndef FALSE
#define FALSE 0
#define TRUE (!FALSE)
#endif

typedef int BOOL;
typedef int qboolean;
typedef unsigned long ULONG;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef unsigned short word;

typedef float vec_t;

#ifndef UNUSED
#define UNUSED(x)	(x = x)	// for pesky compiler / lint warnings
#endif

struct vrect_t
{
	int      x, y, width, height;
	vrect_t* pnext;
};

#endif // BASETYPES_H
