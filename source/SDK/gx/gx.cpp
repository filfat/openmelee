#include "../../libs/termcolor.hpp"

#include "gx.h"
#include "../../stub/stub.h"

namespace GX {
    GX::GXFifoObj* main_fifo;

    GXFifoObj* GXInit (void* base, uint32_t size) {
        main_fifo = new GXFifoObj();
        return main_fifo;
    }

    int32_t GXSetMisc (int32_t u1, int32_t u2) {
        return stub();
    }
}