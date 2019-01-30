#include "gx.h"
#include "../stub/stub.h"

namespace GX {
    __int32_t GXInit (void) {
        if(!glfwInit()) {
            return -1;
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window;
        window = glfwCreateWindow(584, 480, "Super Smash Bros. Melee", NULL, NULL);

        return stub();
    }

    __int32_t GXSetMisc (__int32_t u1, __int32_t u2) {
        return stub();
    }
}