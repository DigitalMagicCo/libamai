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

#include "../include/amai_utility.h"
#include "../include/amai_utility++.hpp"

#include <stddef.h>

#include <Windows.h>

#include <string>
#include <vector>
#include <sstream>

static std::string errorString = "";
static std::vector<HMODULE> locals;

void* dlopen(const char* file, int mode)
{
	// If Windows fails to load the library, it displays a scary error message,
	// and we don't want that.
	UINT previousErrorMode = SetErrorMode(SEM_FAILCRITICALERRORS);

	// If file is null, then we need to return a global handle for the current executable.
	if (file == NULL)
	{
		// Passing NULL into GetModuleHandle returns a handle for the current executable.
		return (void*)GetModuleHandle(NULL);
	}

	// Convert /'s to \'s for LoadLibraryEx
	const char* imageFile = amaiConvertSlashes(file);

	HMODULE image = LoadLibraryExA(imageFile, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);

	// Reset the error mode to the previous setting.
	SetErrorMode(previousErrorMode);

	return (void*)image;
}

int dlclose(void* handle)
{
	if (handle == nullptr)
	{
		errorString = "Amai: dlclose() - Could not close handle because it was NULL.";

		return -1;
	}

	HMODULE mod = (HMODULE)handle;

	BOOL retVal = FreeLibrary(mod);

	if (!retVal)
	{
		std::stringstream ss;
		LPSTR modFileName = new char[MAX_PATH];

		DWORD modFileNameSize = GetModuleFileNameA(mod, modFileName, MAX_PATH);

		ss << "Amai: dlclose() - Unable to close handle to the library (" << modFileName << ") - Windows says: " << GetLastErrorAsString();

		errorString = ss.str();

		delete[] modFileName;
		
		// POSIX is 0 on success, but Win32 is non-zero on success.
		return !retVal;
	}

	// POSIX is 0 on success, but Win32 is non-zero on success.
	return !retVal;
}

char* dlerror()
{
	// If there are no errors, POSIX says to return a NULL string.
	if (errorString == "")
	{
		return nullptr;
	}

	return const_cast<char*>(errorString.c_str());
}
