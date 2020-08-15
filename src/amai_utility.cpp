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
	if (!str) return nullptr;

	std::stringstream ss;

	size_t len = strlen(str);

	for (size_t i = 0; i < len; ++i)
	{
		if (str[i] == '/')
		{
			ss << "\\";
		}
		else
		{
			ss << str[i];
		}
	}

	return ss.str().c_str();
}
