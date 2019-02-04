#include "gx.h"
#include "../../stub/stub.h"
#include "../vi/vi.h"

namespace GX {
    GX::GXFifoObj* g_main_fifo;
    GX::GXColor g_clear_color;

    GXFifoObj* GXInit (void* base, uint32_t size) {
        g_main_fifo = new GXFifoObj();
        return g_main_fifo;
    }

    int32_t GXSetMisc (int32_t u1, int32_t u2) {
        return stub();
    }
    void GXSetCopyClear (GX::GXColor color, uint32_t z) {
        GX::g_clear_color = color;
    }

    void GXDrawBegin (void) {
        // Get fb size
        int32_t width, height;
        glfwGetFramebufferSize(VI::g_window, &width, &height);

        // Set viewport
        glViewport(0, 0, width, height);

        // Set clear color and clear
        glClearColor(GX::g_clear_color.r, GX::g_clear_color.g, GX::g_clear_color.b, GX::g_clear_color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void GXDrawDone (void) {
        glfwSwapBuffers(VI::g_window);

        // Should probably be moved to the Pad namespace.
        glfwPollEvents();
    }
}