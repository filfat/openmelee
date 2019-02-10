#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../os/os.h"

namespace VI {
    extern GLFWwindow* g_window;
    
    void VIInit (void);         // 8034ee9c
    int32_t VIExit (void);      // not official
    bool VIShouldCloseWindow(); // not official
}