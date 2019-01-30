#pragma once

#include <iostream>
#include <time.h>

namespace OS {
    void OSInit (void);                                                 // 80342fc8
    void OSInitAlarm(void);                                             // 80343720

    void OSReport(const char *out, ...);
    void OSPanic(char* file, int line, char* out, ...);

    __uint32_t OSGetPhysicalMemSize(void);
    __uint32_t OSGetConsoleSimulatedMemSize(void);                      // 80347bf0
    void* OSAllocFromArenaHi(__uint32_t size, __uint32_t align);        // 80344514

    __int32_t OSGetTick(void);                                          // 8034c408
}