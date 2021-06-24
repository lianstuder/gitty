#pragma once

// Standard Library
#include <iostream>
#include <functional>

// Data Structures
#include <string>
#include <vector>

// libgit2
#include <git2.h>

// Platform Detection
#ifdef _WIN32
#include <Windows.h>
#define GT_WINDOWS
#ifdef _MSC_VER
#define GT_MSVC
#endif
#elif __APPLE__
#define GT_APPLE
#elif __linux__
#define GT_LINUX
#elif __unix__
#define GT_UNIX
#endif
