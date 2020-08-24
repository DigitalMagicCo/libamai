// alarm.h
// (part of unistd) alarm signal scheduling
//
// Created by Josh Kennedy on 15 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_UNISTD_ALARM_H_
#define DM_AMAI_UNISTD_ALARM_H_

#include "../amai_library.h"

// Warning! Windows doesn't support the core functionality
//	of the alarm() function, which is SIGALRM
// We may have to emulate alarm with threads and funcptrs.

AMAI_API unsigned alarm(unsigned seconds); 

#endif
