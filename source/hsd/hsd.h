#pragma once

#include <iostream>

namespace HSD {
    __int32_t HSDInitComponent(void);
    __int32_t HSDSetInitParameter(int32_t u1, int32_t u2);
    __int32_t HSDAllocateXFB(int32_t u1, int32_t u2);
    __int32_t HSDAllocateFIFO(int32_t u1);
    __int32_t HSDGXSetFifoObj(int32_t u1);
    __int32_t HSDVISetUserPostRetraceCallback(void);
    __int32_t HSDVISetBlack(int32_t u1);
}