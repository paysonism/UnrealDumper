// payson1337 pch.h: This is a precompiled header file.
// payson1337 Files listed below are compiled only once, improving build performance for future builds.
// payson1337 This also affects IntelliSense performance, including code completion and many code browsing features.
// payson1337 However, files listed here are ALL re-compiled if any one of them is updated between builds.
// payson1337 Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// payson1337 add headers that you want to pre-compile here
#include "framework.h"

#include "buildSettings.h"

#include <cstdint>
#include <string>
#include <vector>
#include <locale>
#include <string>
#include <chrono>
#include <fstream>
#include <format>
#include <unordered_map>

struct Ofstreams {
    std::ofstream Classes;
    std::ofstream Functions;
    std::ofstream Structs;
    // payson1337 std::ofstream Parameters;
};

#include "include/memory.h"
#include "offsets.h"
#include "utils.h"

#include "CoreUObject/UObject/Class.h"

#endif //PCH_H
