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
        GLuint GLLoadShaders(const char * vertex_file_path, const char * fragment_file_path);
    }
}