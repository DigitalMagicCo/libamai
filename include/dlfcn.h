// dlfcn.h
// dynamic linking
//
// Created by Josh Kennedy on 14 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

// Portions of this code is based on code from the FreeBSD project.
// Their code is licensed under the BSD license.
//
// Copyright (c) 1992-2020 The FreeBSD Project.
// Copyright 1979, 1980, 1983, 1986, 1988, 1989, 1991, 1992, 1993, 1994
//	The Regents of the University of California. All rights reserved.

#pragma once

#ifndef DM_AMAI_DLFCN_H_
#define DM_AMAI_DLFCN_H_

#include "amai_library.h"

AMAI_C_API void* dlopen(const char* file, int mode);
AMAI_C_API int dlclose(void* handle);
AMAI_C_API char* dlerror();
AMAI_C_API void* dlsym(void* handle, const char* name);

#define RTLD_LAZY 1
#define RTLD_NOW 2
#define RTLD_MODEMASK 0x3
#define RTLD_GLOBAL 0x100
#define RTLD_LOCAL 0
#define RTLD_TRACE 0x200
#define RTLD_NODELETE 0x01000
#define RTLD_NOLOAD 0x02000
#define RTLD_DEEPBIND 0x04000

#define RTLD_NEXT ((void*) -1)
#define RTLD_DEFAULT ((void*) -2)
#define RTLD_SELF ((void*) -3)

#endif
