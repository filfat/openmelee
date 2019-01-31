#pragma once

#include <iostream>
#include <stdarg.h>
#include <time.h>
#include <ctime>
#include <iostream>

namespace OS {
    void OSInit (void);                                                 // 80342fc8
    void OSInitAlarm(void);                                             // 80343720

    void OSReport(const char *out, ...);
    void OSHalt(const char *out, ...);
    void OSPanic(const char* file, int line, const char* out, ...);

    uint32_t OSGetPhysicalMemSize(void);
    uint32_t OSGetConsoleSimulatedMemSize(void);                        // 80347bf0
    void* OSAllocFromArenaHi(uint32_t size, uint32_t align);            // 80344514

    // Time
    // ==============================================================

    typedef struct OSCalendarTime {
        int32_t sec;    // seconds after the minute [0, 61]
        int32_t min;    // minutes after the hour [0, 59]
        int32_t hour;   // hours since midnight [0, 23]
        int32_t mday;   // day of the month [1, 31]
        int32_t mon;    // month since January [0, 11]
        int32_t year;   // years in AD [1, ...]
        int32_t wday;   // days since Sunday [0, 6]
        int32_t yday;   // days since January 1 [0, 365]

        int32_t msec;   // milliseconds after the second [0, 999]
        int32_t usec;   // microseconds after the millisecond [0, 999]
    } OSCalendarTime;

    int32_t OSGetTick(void); // 8034c408
    void OSTicksToCalendarTime(int32_t time, OSCalendarTime *calendar);
}