// alarm.cpp
// (part of unistd) alarm signal scheduling
//
// Created by Josh Kennedy on 15 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#include "../../include/unistd.h"

#include "../../include/__signal.h"

#include <signal.h>

unsigned alarm(unsigned seconds)
{
	if (seconds == 0)
	{
		// Clear out existing timer.
		__signal(SIGALRM, SIG_DFL);

		return 0;
	}

	// this is hard to impl on windows without involving threads....
}
