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

#include <Windows.h>

int chdir(const char* path)
{
	if (!path)
	{
		return -1;
	}

	if (SetCurrentDirectoryA(path) == FALSE)
	{
		// TODO: Set errno
		// Question: What possible codes will GetLastError() return for this failed call?
		return -1;
	}

	return 0;
}
