#include "../../libs/termcolor.hpp"

#include "os.h"
#include "../../stub/stub.h"
#include "../../logger/logger.h"

namespace OS {
    void OSInit (void) {
        // TODO: Init things like a global logger here etc
    }

    void OSInitAlarm(void) {
        stub();
    }
    
    void OSReport(const char *out, ...) {
        va_list args;
        va_start(args, out);
        std::cout << termcolor::blue << "(OSReport) " << termcolor::reset;
        vprintf(out, args);
        va_end(args);
    }
    void OSPanic(const char* file, int line, const char* out, ...) {
        std::cout << termcolor::red << "(FATAL)    " << termcolor::reset << file << ':' << line << ' ' << out << std::endl;
        exit(1);
    }

    uint32_t OSGetPhysicalMemSize(void) {
        return OSGetConsoleSimulatedMemSize();
    }

    uint32_t OSGetConsoleSimulatedMemSize(void) {
        return 0x1800000;
    }

    void* OSAllocFromArenaHi(uint32_t size, uint32_t align) {
		return (void*)stub();
        //return (void*)aligned_alloc(align, size);
    }

    // Time
    // ==============================================================

    int32_t OSGetTick(void) {
        return time(0);
    }

    void OSTicksToCalendarTime(int32_t time, OS::OSCalendarTime *calendar) {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);

        calendar->sec   = now->tm_sec;
        calendar->min   = now->tm_min;
        calendar->hour  = now->tm_hour;
        calendar->mday  = now->tm_mday;
        calendar->mon   = now->tm_mon;
        calendar->year  = (1900 + now->tm_year);
        calendar->wday  = now->tm_wday;
        calendar->yday  = now->tm_yday;

        calendar->msec  = 0; // FIXME:
        calendar->usec  = 0; // FIXME:
    }
}