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

        if(!glfwInit()) {
            OS::OSPanic(__FILE__, __LINE__, "VIInit->Failed initialize GLFW");
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        VI::g_window = glfwCreateWindow(640, 480, "OpenMelee", NULL, NULL);

        std::cout << termcolor::blue << "(VI)       " << termcolor::reset;
        printf("VIInit->Info: Created window\n");
    }

    bool VIShouldCloseWindow() {
        return glfwWindowShouldClose(VI::g_window);
    }
}