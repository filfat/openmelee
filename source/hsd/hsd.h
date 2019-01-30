#pragma once

#include <iostream>

#include "../gx/gx.h"

namespace HSD {
    extern GX::GXFifoObj* main_fifo;

    __int32_t HSDInitComponent(void);
    __int32_t HSDSetInitParameter(int32_t u1, int32_t u2);  // 803756f8
    __int32_t HSDAllocateXFB(int32_t u1, int32_t u2);       // 80374f7c
    __int32_t HSDAllocateFIFO(int32_t u1);                  // 80375194
    __int32_t HSDGXSetFifoObj(GX::GXFifoObj *fifo);         // 80374f60
    __int32_t HSDVISetUserPostRetraceCallback(void);
    __int32_t HSDVISetBlack(bool off);                      // 803767a0
}