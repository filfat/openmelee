#include "gx.h"
#include "../stub/stub.h"

namespace GX {
    GLFWwindow* window;

    GXFifoObj* GXInit (void* base, __uint32_t size) {
        if(!glfwInit()) {
            OS::OSPanic(__FILE__, __LINE__, "Failed initialize GLFW");
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GX::window = glfwCreateWindow(584, 480, "OpenMelee", NULL, NULL);

        stub();
        return NULL;
    }

    __int32_t GXSetMisc (__int32_t u1, __int32_t u2) {
        return stub();
    }
}