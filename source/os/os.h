#pragma once

#include <iostream>
#include <stdarg.h>
#include <time.h>

namespace OS {
    void OSInit (void);                                                 // 80342fc8
    void OSInitAlarm(void);                                             // 80343720

    void OSReport(const char *out, ...);
    void OSPanic(const char* file, int line, const char* out, ...);

    uint32_t OSGetPhysicalMemSize(void);
    uint32_t OSGetConsoleSimulatedMemSize(void);                      // 80347bf0
    void* OSAllocFromArenaHi(uint32_t size, uint32_t align);        // 80344514

    int32_t OSGetTick(void);                                          // 8034c408
}