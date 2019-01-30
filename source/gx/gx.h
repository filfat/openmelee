#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GX {
    __int32_t GXInit (void);

    __int32_t GXSetMisc (__int32_t u1, __int32_t u2);
}