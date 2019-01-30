#pragma once

#include <iostream>

namespace OS {
    __int32_t OSInit (void);
    __int32_t OSInitAlarm(void);

    void OSReport (const char *out, __int32_t *u1);
    int32_t OSPanic(__int32_t u1, __int32_t *u2, __int32_t u3, __int32_t u4);

    __uint32_t OSGetConsoleSimulatedMemSize(void);
    __int32_t OSAllocFromArenaHi(int32_t u1, int32_t u2);

    __int32_t OSGetTick(void);
}