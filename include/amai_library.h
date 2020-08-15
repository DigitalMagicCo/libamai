// amai_libary.h
// function decorators to export to/import from DLL
//
// Created by Josh Kennedy on 14 August 2020
//
// Amai
// Copyright (C) 2020 DigitalMagic, LLC.
//
// Licensed under Apache 2.0 License.
// See the LICENSE file at the project root.

#pragma once

#ifndef DM_AMAI_LIBRARY
#define DM_AMAI_LIBRARY

#ifndef AMAI_STATIC
#ifdef AMAI_EXPORT
#define AMAI_API __declspec(dllexport)
#define AMAI_C_API extern "C" AMAI_API
#else
#define AMAI_API __declspec(dllimport)
#define AMAI_C_API extern "C" AMAI_API
#endif
#else
#define AMAI_API
#define AMAI_C_API extern "C"
#endif

#endif
