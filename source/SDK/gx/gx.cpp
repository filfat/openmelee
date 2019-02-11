#include "gx.h"
#include "../../stub/stub.h"
#include "../vi/vi.h"
#include "../../../libs/termcolor.hpp"

namespace GX {
    GX::GXFifoObj* g_main_fifo;
    GX::GXColor g_clear_color;

    GLuint g_program;

    std::vector<GLfloat> g_vertex_data;
    u_int32_t g_vertex_data_size;
    u_int32_t g_vertex_data_index;
    GLuint g_vertex_buffer;
    GLenum g_vertex_type;

    GXFifoObj* GXInit (void* base, uint32_t size) {
        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

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

        glUseProgram(GX::g_program);
    }
    void GXDrawDone (void) {
        glfwSwapBuffers(VI::g_window);

        // Should probably be moved to the Pad namespace.
        glfwPollEvents();
    }

    void GXBegin (GX::GXPrimitive type, GXVtxFmt vtxfmt, u_int32_t nverts) {
        GLenum gl_type = GL_TRIANGLES;

        switch(type) {
            case GX_TRIANGLES:
                break;
            case GX_POINTS:
                gl_type = GL_POINTS;
                break;
            case GX_LINES:
                gl_type = GL_LINES;
                break;
            case GX_TRIANGLESTRIP:
                gl_type = GL_TRIANGLE_STRIP;
                break;
            case GX_QUADS: 
                gl_type = GL_QUADS;
                break;
            default:
                stub();
        };

        glGenBuffers(1, &g_vertex_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, g_vertex_buffer);

        g_vertex_data.clear();
        g_vertex_data_index = 0;
        g_vertex_type = gl_type;
        g_vertex_data_size = sizeof(g_vertex_data.data()) * sizeof(GLfloat);
    }
    void GXEnd (void) {
        glBufferData(GL_ARRAY_BUFFER, g_vertex_data_size, g_vertex_data.data(), GL_STREAM_DRAW);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, g_vertex_buffer);
        glVertexAttribPointer(
            0,
            2,
            GL_FLOAT,
            GL_FALSE,
            2 * sizeof(GLfloat), // FIXME:
            (const void*)0
        );

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);
    }

    void GXPosition2f32(GLfloat x, GLfloat y) {
        GX::g_vertex_data.push_back(x);
        GX::g_vertex_data.push_back(y);
        g_vertex_data_index += 1;
    }
    void GXPosition3f32(GLfloat x, GLfloat y, GLfloat z) {
        GX::g_vertex_data.push_back(x);
        GX::g_vertex_data.push_back(y);
        GX::g_vertex_data.push_back(z);
        g_vertex_data_index += 1;
    }
}