#pragma once

#include <iostream>

namespace OS {
    __int32_t OSInit (void);
    __int32_t OSInitAlarm(void);

    void OSReport (std::string out, __int32_t u1);
    __uint32_t OSGetConsoleSimulatedMemSize(void);
    __int32_t OSAllocFromArenaHi(int32_t u1, int32_t u2);
}