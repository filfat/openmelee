#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../os/os.h"

namespace GX {
    typedef enum {
        GX_POINTS,
        GX_LINES,
        GX_LINESTRIP,
        GX_TRIANGLES,
        GX_TRIANGLESTRIP,
        GX_TRIANGLEFAN,
        GX_QUADS
    } GXPrimitive;
    typedef enum {
        GX_VTXFMT0,
        GX_VTXFMT1,
        GX_VTXFMT2,
        GX_VTXFMT3,
        GX_VTXFMT4,
        GX_VTXFMT5,
        GX_VTXFMT6,
        GX_VTXFMT7,
        GX_MAX_VTXFMT
    } GXVtxFmt;

    typedef struct {
        uint8_t pad[128];
    } GXFifoObj;
    typedef struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } GXColor;

    extern GXFifoObj* g_main_fifo;
    extern GX::GXColor g_clear_color;

    extern GLuint g_program;

    extern std::vector<GLfloat> g_vertex_data;
    extern u_int32_t g_vertex_data_index;
    extern GLuint g_vertex_buffer;
    extern GLenum g_vertex_type;

    GXFifoObj* GXInit (void* base, uint32_t size);      // 8033a780
    void GXExit (void);                                 // not official
    int32_t GXSetMisc (int32_t u1, int32_t val);        // 8033cbc0
    void GXSetCopyClear (GX::GXColor color, uint32_t z);

    void GXDrawBegin (void);                            // not official
    void GXDrawDone (void);

    void GXBegin (GX::GXPrimitive type, GXVtxFmt vtxfmt, u_int32_t nverts);
    void GXEnd (void);

    void GXPosition2f32(GLfloat x, GLfloat y);
    void GXPosition3f32(GLfloat x, GLfloat y, GLfloat z);
}