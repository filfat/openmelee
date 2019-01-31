#include "vi.h"
#include "../../stub/stub.h"

namespace VI {
    //GLFWwindow* g_window;

    int32_t VIInit (void) {
        /*if(!glfwInit()) {
            OS::OSPanic(__FILE__, __LINE__, "VIInit->Failed initialize GLFW");
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GX::g_window = glfwCreateWindow(640, 240, "OpenMelee", NULL, NULL);

        std::cout << termcolor::blue << "(VI)       " << termcolor::reset;
        printf("VIInit->Info: Created window\n");*/

        return stub();
    }
}