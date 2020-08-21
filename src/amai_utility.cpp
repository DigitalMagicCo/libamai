// amai_utility.cpp
// common utilities
//
// Created by Josh Kennedy on 14 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#include "../include/amai_utility.h"

#include "../include/amai_library.h"

#include <sstream>

const char* amaiConvertSlashes(const char* str)
{
	char* newString;
	size_t len = 0;

	if (!str) return NULL;
	
	len = strlen(str);

	newString = (char*)malloc(sizeof(char) * len + 1);

	for (size_t i = 0; i < len; ++i)
	{
		if (str[i] == '/')
		{
			newString[i] = (char)0x5C; // backslash character
		}
		else
		{
			newString[i] = str[i];
		}
	}

	newString[len] = NULL;

	return newString;
}
