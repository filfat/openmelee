#include "gx.h"
#include "../../stub/stub.h"

namespace GX {
    GX::GXFifoObj* g_main_fifo;

    GXFifoObj* GXInit (void* base, uint32_t size) {
        g_main_fifo = new GXFifoObj();
        return g_main_fifo;
    }

    int32_t GXSetMisc (int32_t u1, int32_t u2) {
        return stub();
    }
}