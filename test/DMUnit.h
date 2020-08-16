// DMUnit.h
// Simple C/C++ Unit Testing
//
// Created by Josh Kennedy
//
// Copyright (C) 2017-2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_DMUNIT_H_
#define DM_DMUNIT_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#if _DEBUG
#if _MSC_VER
#include <intrin.h>
#define BREAKPOINT() __debugbreak()
#else
#include <signal.h>
#define BREAKPOINT() raise(SIGINT);
#endif
#else
#define BREAKPOINT() (void)0
#endif

#ifndef __FUNCSIG__
#define __FUNCSIG__ __PRETTY_FUNCTION__
#endif

#define TEST_SUCCESS 0
#define TEST_FAIL 1

#define ASSERT_WITH_MESSAGE(msg, ...) printf("%s in method %s on line %d\n", \
	msg, __VA_ARGS__, __FUNCSIG__, __LINE__); BREAKPOINT(); return TEST_FAIL;

#define ASSERT() ASSERT_WITH_MESSAGE("Assertion failed")

#define ASSERT_TRUE(x) if (x != true) { ASSERT_WITH_MESSAGE("Expected true not false") }
#define ASSERT_FALSE(x) if (x != false) { ASSERT_WITH_MESSAGE("Expected false not true") }

#define ASSERT_NULL(x) if (x) { ASSERT_WITH_MESSAGE("Expected NULL, got something else") }
#define ASSERT_NOT_NULL(x) if (!x) { ASSERT_WITH_MESSAGE("Unexpected NULL received") }

#define ASSERT_EQUALS(x, y) if (x != y) { ASSERT() }
#define ASSERT_NOT_EQUALS(x, y) if (x == y) { ASSERT() }

#define ASSERT_STR_EQUALS(x, y) if (strcmp(x, y) != 0) { ASSERT() }
#define ASSERT_STR_NOT_EQUALS(x, y) if (strcmp(x, y) == 0) { ASSERT() }

typedef int(*DMTestFunction)();

void runTest(DMTestFunction func, const char* name)
{
	int retVal = func();

	printf("%s:", name);

	if (retVal)
	{
		printf("OK");
	}
	else
	{
		printf("FAILURE");
	}

	printf("\n");
}


#endif
