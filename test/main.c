// main.c
// driver program for the unit tests.
//
// Created by Josh Kennedy on 16 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#define DMUNIT_IMPL

#include "DMUnit.h"

#include "amai_utility_test.h"

int main(int argc, char* argv[])
{
	runAmaiUtilityTests();

	return 0;
}
