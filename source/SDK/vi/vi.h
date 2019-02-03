#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../os/os.h"

namespace VI {
    extern GLFWwindow* g_window;
    
    int32_t VIInit (void);      // 8034ee9c
    bool VIShouldCloseWindow(); // not official
}