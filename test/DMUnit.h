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

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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

#define __GET_ASSERTION_INFO() char* asinfo = malloc(512 * sizeof(char)); sprintf(asinfo, "in method %s on line %d in file %s", __FUNCSIG__, __LINE__, __FILE__);

#define ASSERT_WITH_MESSAGE(msg) __GET_ASSERTION_INFO() printf("%s %s\n", \
	msg, asinfo); BREAKPOINT(); return TEST_FAIL;

#define ASSERT() ASSERT_WITH_MESSAGE("Assertion failed")

#define ASSERT_TRUE(x) if (x != true) { ASSERT_WITH_MESSAGE("Expected true not false") }
#define ASSERT_FALSE(x) if (x != false) { ASSERT_WITH_MESSAGE("Expected false not true") }

#define ASSERT_NULL(x) if (x) { ASSERT_WITH_MESSAGE("Expected NULL, got something else") }
#define ASSERT_NOT_NULL(x) if (!x) { ASSERT_WITH_MESSAGE("Unexpected NULL received") }

#define ASSERT_EQUALS(x, y) if (x != y) { ASSERT_WITH_MESSAGE("Equality check failed.") }
#define ASSERT_NOT_EQUALS(x, y) if (x == y) { ASSERT_WITH_MESSAGE("Inequality check failed.") }

#define ASSERT_STR_EQUALS(x, y) if (strcmp(x, y) != 0) { char* stringWithVars = malloc(1024 * sizeof(char)); sprintf(stringWithVars, "String \"%s\" not equals \"%s\"", x, y); ASSERT_WITH_MESSAGE(stringWithVars) free(stringWithVars); }
#define ASSERT_STR_NOT_EQUALS(x, y) if (strcmp(x, y) == 0) { char* stringWithVars = malloc(1024 * sizeof(char)); sprintf(stringWithVars, "String \"%s\" equals \"%s\"", x, y); ASSERT_WITH_MESSAGE(stringWithVars) free(stringWithVars); }

typedef int(*DMTestFunction)();

void runTest(DMTestFunction func, const char* name);

#ifdef DMUNIT_IMPL
void runTest(DMTestFunction func, const char* name)
{
	int retVal = func();

	printf("%s: ", name);

	if (retVal == TEST_SUCCESS)
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

#endif
