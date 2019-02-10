#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../os/os.h"

namespace GX {
    typedef struct {
        uint8_t pad[128];
    } GXFifoObj;
    typedef struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } GXColor;

    extern GXFifoObj* g_main_fifo;
    extern GX::GXColor g_clear_color;

    GXFifoObj* GXInit (void* base, uint32_t size);      // 8033a780
    void GXExit (void);                                 // not official
    int32_t GXSetMisc (int32_t u1, int32_t val);        // 8033cbc0
    void GXSetCopyClear (GX::GXColor color, uint32_t z);

    void GXDrawBegin (void);                            // not official
    void GXDrawDone (void);
}