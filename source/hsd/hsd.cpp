#include "hsd.h"
#include "../stub/stub.h"

// Based on HAL's modifications to the offical SDK

namespace HSD {
    GX::GXFifoObj* main_fifo;

    __int32_t HSDInitComponent(void) {
        return stub();
    }

    __int32_t HSDSetInitParameter(int32_t u1, int32_t u2) {
        return stub();
    }

    __int32_t HSDAllocateXFB(int32_t u1, int32_t u2) {
        return stub();
    }

    __int32_t HSDAllocateFIFO(int32_t u1) {
        return stub();
    }

    __int32_t HSDGXSetFifoObj(GX::GXFifoObj *fifo) {
        main_fifo = fifo;
        return 0;
    }

    __int32_t HSDVISetUserPostRetraceCallback(void) {
        return stub();
    }

    __int32_t HSDVISetBlack(bool off) {
        return stub();
    }
}