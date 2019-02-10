#include "gx.h"
#include "../../stub/stub.h"
#include "../vi/vi.h"
#include "../../libs/termcolor.hpp"

namespace GX {
    GX::GXFifoObj* g_main_fifo;
    GX::GXColor g_clear_color;

    GXFifoObj* GXInit (void* base, uint32_t size) {
        g_main_fifo = new GXFifoObj();
        return g_main_fifo;
    }
    void GXExit (void) { return; }

    int32_t GXSetMisc (int32_t u1, int32_t u2) {
        return stub();
    }
    void GXSetCopyClear (GX::GXColor color, uint32_t z) {
        GX::g_clear_color = color;

        GLclampf r = (GLclampf)GX::g_clear_color.r / 255;
        GLclampf g = (GLclampf)GX::g_clear_color.g / 255;
        GLclampf b = (GLclampf)GX::g_clear_color.b / 255;
        GLclampf a = (GLclampf)GX::g_clear_color.a / 255;

        // Set clear color
        glClearColor(r, g, b, a);

        std::cout << termcolor::blue << "(GX)       " << termcolor::reset;
        printf("GXSetCopyClear->r: %f, g: %f, b: %f, a: %f\n", r, g, b, a);
    }

    void GXDrawBegin (void) {
        // Get fb size
        int32_t width, height;
        glfwGetFramebufferSize(VI::g_window, &width, &height);

        // Set viewport
        glViewport(0, 0, width, height);

        // Clear the buffer
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void GXDrawDone (void) {
        glfwSwapBuffers(VI::g_window);

        // Should probably be moved to the Pad namespace.
        glfwPollEvents();
    }
}