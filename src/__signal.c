// __signal.c
// wrapper around win32 signal() so we can intercept SIGALRM and whatever else.
//
// Created by Josh Kennedy on 15 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#include "../include/__signal.h"

#include <stddef.h>

#include <signal.h>

static void(*previousSigalrm)(int) = NULL;
static void(*currentSigalrm)(int) = NULL;

void sigalrm_start_waiting()
{
	
}

void sigalrm_stop_waiting()
{

}

void* __signal(int sig, void(*func)(int))
{
	switch (sig)
	{
	case SIGALRM:
		previousSigalrm = currentSigalrm;
		currentSigalrm = func;

		if (func == SIG_DFL)
		{
			sigalrm_stop_waiting();

			return previousSigalrm;
		}
		
		sigalrm_start_waiting();

		return previousSigalrm;
	default:
		return signal(sig, func);
	}
}
