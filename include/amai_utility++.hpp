// amai_utility++.hpp
// common utilities for C++ code
//
// Created by Josh Kennedy on 24 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_UTILITY_CPP_HPP_
#define DM_AMAI_UTILITY_CPP_HPP_

#include "amai_library.h"

#include <string>

// Returns the last Win32 error, in string format. Returns an empty string if there is no error.
AMAI_API std::string GetLastErrorAsString();

#endif
