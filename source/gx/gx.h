#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../os/os.h"

namespace GX {
    typedef struct {
        __uint8_t pad[128];
    } GXFifoObj;

    extern GLFWwindow* window;
    extern GXFifoObj* main_fifo;

    GXFifoObj* GXInit (void* base, __uint32_t size);    // 8033a780
    __int32_t GXSetMisc (__int32_t u1, __int32_t val);  // 8033cbc0
}