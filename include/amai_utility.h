// amai_utility.h
// common utilities
//
// Created by Josh Kennedy on 14 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_UTILITY_H_
#define DM_AMAI_UTILITY_H_

#include "amai_library.h"

#if __cplusplus
extern "C" {
#endif

// Converts forward slashes (/) to backslashes (\)
AMAI_API const char* amaiConvertSlashes(const char* str);

#if __cplusplus
}
#endif

#endif
