// amai_version.h
// Amai's version information in code.
//
// Created by Josh Kennedy on 14 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic LLC. All rights reserved.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_VERSION_H_
#define DM_AMAI_VERSION_H_

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

// We're using Semantic Versioning, which follows the major.minor.patch schema
// https://semver.org/

// Major version, which signifies that there API backward compatability is not guaranteed.
#define AMAI_VERSION_MAJOR 0

// Minor version, which signifies that it is backward compatibile within the major version release.
#define AMAI_VERSION_MINOR 1

// Patch version, for bugfixes/hotfixes/patches, backward compatibile within the major version release.
#define AMAI_VERSION_PATCH 0

// Version string to include in the RC file or any printfs or whatever.
#define AMAI_VERSION_STRING STR(AMAI_VERSION_MAJOR) "." STR(AMAI_VERSION_MINOR) "." STR(AMAI_VERSION_PATCH)

#endif 
