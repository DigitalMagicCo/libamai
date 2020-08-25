// chdir.h
// (part of unistd) change the current working directory
//
// Created by Josh Kennedy on 24 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_UNISTD_CHDIR_H_
#define DM_AMAI_UNISTD_CHDIR_H_

#include "../amai_library.h"

// Changes the current working directory to the path passed in.
// Returns 0 on success, -1 on failure.
// POSIX says that we should set errno, but that's too hard right now, so just check GetLastError for the time being.
AMAI_API int chdir(const char* path);

#endif
