#pragma once
#define SDL_MAIN_HANDLED

// Standard Library
#include <iostream>
#include <functional>

// Data Structures
#include <string>
#include <vector>

// libgit2
#include <git2.h>

// Platform Detection
#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#else
#error "Unsupported platform."
#endif
