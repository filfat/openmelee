#pragma once

#include <iostream>

#include "../gx/gx.h"

namespace HSD {
    typedef enum {
        HSD_INIT_FIFO_SIZE,
        HSD_INIT_XFB_MAX_NUM,
        HSD_INIT_HEAP_MAX_NUM,
        HSD_INIT_AUDIO_HEAP_SIZE,
        HSD_INIT_RENDER_MODE_OBJ
    } HSDInitParam;

    extern GX::GXFifoObj* g_main_fifo;
    extern int32_t g_init_done;

    int32_t HSDInitComponent(void);
    int32_t HSDSetInitParameter(HSDInitParam param, ...); // 803756f8
    int32_t HSDAllocateXFB(int32_t u1, int32_t u2);       // 80374f7c
    int32_t HSDAllocateFIFO(int32_t u1);                  // 80375194
    int32_t HSDGXSetFifoObj(GX::GXFifoObj *fifo);         // 80374f60
    int32_t HSDVISetUserPostRetraceCallback(void);        // 80375934

    /** \brief Enables/Disables blacking out the screen.
      * \param black true if on, false if of
      * \return void
      * 
      * (803767a0)
      * The change isn't supposed to take effect till
      * after VIFlush() is called.
      */
    int32_t HSDVISetBlack(bool black);
}