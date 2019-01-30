#include "os.h"
#include "../stub/stub.h"

namespace OS {
    __int32_t OSInit (void) {
        return stub();
    }

    __int32_t OSInitAlarm(void) {
        return stub();
    }
    
    void OSReport (std::string out, __int32_t u1) {
        printf((char*)out.c_str());
        stub();
    }

    __uint32_t OSGetConsoleSimulatedMemSize(void) {
        return stub();
    }

    __int32_t OSAllocFromArenaHi(int32_t u1, int32_t u2) {
        return stub();
    }
}