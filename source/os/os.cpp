#include "os.h"
#include "../stub/stub.h"

namespace OS {
    void OSInit (void) {
        stub();
    }

    void OSInitAlarm(void) {
        stub();
    }
    
    void OSReport(const char *out, ...) {
        va_list args;
        va_start(args, out);
        printf("\033[34;1m(OSReport)\033[0m ");
        vprintf(out, args);
        va_end(args);
    }
    void OSPanic(char* file, int line, char* out, ...) {
        printf("\033[31;1m(FATAL)\033[0m    %s:%d %s\n", file, line, out);
        exit(1);
    }

    __uint32_t OSGetPhysicalMemSize(void) {
        return OSGetConsoleSimulatedMemSize();
    }

    __uint32_t OSGetConsoleSimulatedMemSize(void) {
        return 0x1800000;
    }

    void* OSAllocFromArenaHi(__uint32_t size, __uint32_t align) {
        return (void*)aligned_alloc(align, size);
    }

    __int32_t OSGetTick(void) {
        return time(NULL);
    }
}