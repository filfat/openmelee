#include "../../libs/termcolor.hpp"

#include "os.h"
#include "../stub/stub.h"

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

    int32_t OSGetTick(void) {
        return time(NULL);
    }
}