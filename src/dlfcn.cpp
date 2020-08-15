// dlfcn.cpp
// dynamic linking
//
// Created by Josh Kennedy on 14 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#include "../include/dlfcn.h"

#include <stddef.h>

#include <Windows.h>

void* dlopen(const char* file, int mode)
{
	// If file is null, then we need to return a global handle for the current executable.
	if (file == nullptr)
	{
		// Passing NULL into GetModuleHandle returns a handle for the current executable.
		return (void*)GetModuleHandle(nullptr);
	}

	// If Windows fails to load the library, it displays a scary error message,
	// and we don't want that.
	UINT previousErrorMode = SetErrorMode(SEM_FAILCRITICALERRORS);



	// Reset the error mode to the previous setting.
	SetErrorMode(previousErrorMode);

	return nullptr;
}
