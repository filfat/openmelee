#include "vi.h"
#include "../../stub/stub.h"
#include "../../libs/termcolor.hpp"

static void glfwError(int id, const char* description) {
    std::cout << termcolor::blue << "(VI)       " << termcolor::reset;
    printf("GLFW->Error: %s\n", description);
}

namespace VI {
    GLFWwindow* g_window;

    void VIInit (void) {
        glfwSetErrorCallback(&glfwError);

        if(glfwInit() != GL_TRUE) {
            OS::OSPanic(__FILE__, __LINE__, "VIInit->Failed initialize GLFW");
            return;
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        VI::g_window = glfwCreateWindow(640, 480, "OpenMelee", NULL, NULL);
        if(g_window == nullptr) {
            OS::OSPanic(__FILE__, __LINE__, "VIInit->Failed to create window");
            return;
        }

        std::cout << termcolor::blue << "(VI)       " << termcolor::reset;
        printf("VIInit->Info: Created window\n");

        glfwMakeContextCurrent(g_window);

        glewExperimental = GL_TRUE;
        if(glewInit() != GLEW_OK) {
            OS::OSPanic(__FILE__, __LINE__, "VIInit->Failed initialize GLEW");
            return;
        }
    }
    int32_t VIExit (void) {
        glfwTerminate();
        return 0;
    }

    bool VIShouldCloseWindow() {
        return glfwWindowShouldClose(VI::g_window);
    }
}
