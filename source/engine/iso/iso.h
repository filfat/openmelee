#pragma once
#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <string.h>

namespace Engine {
    namespace ISO {
        int32_t ExtractISO (const char* path);
    }
}