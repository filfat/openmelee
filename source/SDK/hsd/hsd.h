#pragma once

#include <iostream>

#include "../gx/gx.h"

namespace HSD {
    extern GX::GXFifoObj* main_fifo;

    int32_t HSDInitComponent(void);
    int32_t HSDSetInitParameter(int32_t u1, int32_t u2);  // 803756f8
    int32_t HSDAllocateXFB(int32_t u1, int32_t u2);       // 80374f7c
    int32_t HSDAllocateFIFO(int32_t u1);                  // 80375194
    int32_t HSDGXSetFifoObj(GX::GXFifoObj *fifo);         // 80374f60
    int32_t HSDVISetUserPostRetraceCallback(void);        // 80375934
    int32_t HSDVISetBlack(bool off);                      // 803767a0
}