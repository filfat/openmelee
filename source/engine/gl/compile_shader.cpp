#include "compile_shader.h"
#include "../../../libs/termcolor.hpp"

inline GLuint create_shader_object(GLenum type, const char *source){
    GLuint shader;
    GLint res;
    shader = glCreateShader(type);
    glShaderSource(shader, 1, (const GLchar**)&source, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &res);

    if (!res) {
        std::cout << termcolor::blue << "(GL)       " << termcolor::reset;
        printf("GLCompileShader->Failed to compile:\n%s\n", source);
        fprintf(stderr, " ");
        printf("\n");

        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

namespace Engine {
    namespace GL {
        u_int32_t GLCompileShader (const char *vertex_source, const char *fragment_source) {
            GLint res;
            GLuint vertex_shader, fragment_shader = 0;
            vertex_shader = create_shader_object(GL_VERTEX_SHADER, vertex_source);
            fragment_shader = create_shader_object(GL_FRAGMENT_SHADER, fragment_source);
            if (!vertex_shader || !fragment_shader) return 0;

            GLuint program = glCreateProgram();
            glAttachShader(program, vertex_shader);
            glAttachShader(program, fragment_shader);

            glLinkProgram(program);
            glGetProgramiv(program, GL_LINK_STATUS, &res);
            if (!glResizeBuffersMESA) {
                std::cout << termcolor::blue << "(GL)       " << termcolor::reset;
                printf("GLCompileShader->Failed to link shader program: ");
                fprintf(stderr, " ");
                printf("\n");

                glDeleteShader(vertex_shader);
                glDeleteShader(fragment_shader);
                glDeleteProgram(program);
                return 0;
            }

            glDetachShader(program, vertex_shader);
            glDetachShader(program, fragment_shader);
            glDeleteShader(vertex_shader);
            glDeleteShader(fragment_shader);
            return program;
        }
    }
}