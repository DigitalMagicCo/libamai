// __signal.h
// wrapper around win32 signal() so we can intercept SIGALRM and whatever else.
//
// Created by Josh Kennedy on 15 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_SIGNAL_H_
#define DM_AMAI_SIGNAL_H_

#include "amai_library.h"

// Alarm clock.
#define SIGALRM 99

AMAI_API void* __signal(int sig, void(*func)(int));

#endif
