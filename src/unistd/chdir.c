// chdir.c
// (part of unistd) change the current working directory
//
// Created by Josh Kennedy on 24 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#include "../../include/unistd/chdir.h"

#include <errno.h>
#include <string.h>

#include <Windows.h>

int chdir(const char* path)
{
	if (!path)
	{
		errno = ENOENT;

		return -1;
	}

	if (SetCurrentDirectoryA(path) == FALSE)
	{
		// There are 15999 error codes, which one could this function possibly throw?
		// https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes
		DWORD errorCode = GetLastError();

		// I guess we can try to guess what the error may be?

		// If the path is too large, then that may be the error?
		// TODO: Windows 10 - 1607 can have long paths enabled: https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation
		size_t pathLength = strlen(path);

		if (pathLength >= _MAX_PATH)
		{
			errno = ENAMETOOLONG;
		}

		// TODO: Set errno
		return -1;
	}

	return 0;
}
