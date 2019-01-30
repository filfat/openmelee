#include "os.h"
#include "../stub/stub.h"

namespace OS {
    __int32_t OSInit (void) {
        return stub();
    }

    __int32_t OSInitAlarm(void) {
        return stub();
    }
    
    void OSReport (const char *out, __int32_t *u1) {
        printf(out);
    }

    __uint32_t OSGetConsoleSimulatedMemSize(void) {
        return stub();
    }

    __int32_t OSAllocFromArenaHi(int32_t u1, int32_t u2) {
        return stub();
    }

    __int32_t OSGetTick(void) {
        return stub();
    }
}