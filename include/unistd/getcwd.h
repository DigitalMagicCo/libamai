// getcwd.h
// (part of unistd) retrieves the current working directory
//
// Created by Josh Kennedy on 24 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_UNISTD_GETCWD_H_
#define DM_AMAI_UNISTD_GETCWD_H_

#include "../amai_library.h"

AMAI_API char* getcwd(char* buf, size_t size);

#endif
