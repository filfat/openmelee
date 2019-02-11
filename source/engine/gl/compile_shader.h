#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
    namespace GL {
        u_int32_t GLCompileShader (const char *vertex_source, const char *fragment_source);
    }
}