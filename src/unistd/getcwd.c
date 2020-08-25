// getcwd.c
// (part of unistd) retrieves the current working directory
//
// Created by Josh Kennedy on 24 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#include "../../include/unistd.h"

#include <Windows.h>

#include <errno.h>

char* getcwd(char* buf, size_t size)
{
	DWORD val = 0;

	if (size == 0)
	{
		errno = EINVAL;

		// POSIX says to clear buf, and to return NULL.
		buf = NULL;

		return NULL;
	}

	val = GetCurrentDirectoryA(size, buf);

	if (val > size)
	{
		errno = ERANGE;

		// POSIX says to clear buf, and to return NULL.
		buf = NULL;

		return NULL;
	}
	else if (val == 0)
	{
		// Since this is a GetLastError situation, what do we set errno to?

		// POSIX says to clear buf, and to return NULL.
		buf = NULL;

		return NULL;
	}

	return buf;
}
