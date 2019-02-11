#include "hsd.h"
#include "../../stub/stub.h"
#include "../os/os.h"

// Based on HAL's modifications to the offical SDK

namespace HSD {
    GX::GXFifoObj *g_main_fifo;
    int32_t g_init_done;

    int32_t HSDInitComponent(void) {
        g_init_done = 1;
        return stub();
    }

    int32_t HSDSetInitParameter(HSDInitParam param, ...) {
        if (g_init_done <= 0) {
            OS::OSPanic(__FILE__, __LINE__, "You need to run HSDInitComponent before HSDSetInitParameter.");
            return -1;
        }
        return stub();
    }

    int32_t HSDAllocateXFB(int32_t u1, int32_t u2) {
        return stub();
    }

    int32_t HSDAllocateFIFO(int32_t u1) {
        return stub();
    }

    int32_t HSDGXSetFifoObj(GX::GXFifoObj *fifo) {
        g_main_fifo = fifo;
        return 0;
    }

    int32_t HSDVISetUserPostRetraceCallback(void) {
        return stub();
    }

    int32_t HSDVISetBlack(bool off) {
        return stub();
    }
}