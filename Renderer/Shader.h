#pragma once

#include "../Glad/include/glad/glad.h"
#include <stdint.h>
#include <stdio.h>

typedef struct
{
    uint32_t id;
} Shader;

inline Shader CompileShader(const char* vertexShader, const char* fragmentShader)
{
    Shader shader;
    uint32_t vertShaderU = 0;
    uint32_t fragShaderU = 0;

    int success;
    char infoLog[512];
    vertShaderU = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShaderU, 1, &vertexShader, NULL);
    glCompileShader(vertShaderU);
    glGetShaderiv(vertShaderU, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertShaderU, 512, NULL, infoLog);
        printf("Shader type Vertex Failed Compile\n");
        printf(infoLog + "\n");
    }

    fragShaderU = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShaderU, 1, &fragmentShader, NULL);
    glCompileShader(fragShaderU);
    glGetShaderiv(fragShaderU, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragShaderU, 512, NULL, infoLog);
        printf("Shader type Fragment Failed Compile\n");
        printf(infoLog + "\n");
    }

    shader = glCreateProgram();

    glAttachShader(shader.id, vertShaderU);
    glAttachShader(shader.id, fragShaderU);
    glLinkProgram(shader.id);
    glGetProgramiv(shader.id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader.id, 512, NULL, infoLog);
        printf("Shader failed linking\n");
        printf(infoLog + "\n");
    }

    //maybe will create problem
    glDetachShader(shader.id, vertShaderU);
    glDetachShader(shader.id, fragShaderU);

    glDeleteShader(vertShaderU);
    glDeleteShader(fragShaderU);

    return shader;
}

inline void ShaderSetInt(char name[], const int value, const Shader shader)
{
    glUniform1i(glGetUniformLocation(shader.id, name), value);
}

inline void ShaderSetFloat(char name[], const float value, const Shader shader)
{
    glUniform1f(glGetUniformLocation(shader.id, name), value);
}

inline void ShaderSetVec2(char name[], void* vec2, const Shader shader)
{
    glUniform2fv(glGetUniformLocation(shader.id, name), 1, vec2);
}

inline void ShaderSetVec2Ex(char name[], float x, float y, const Shader shader)
{
    glUniform2f(glGetUniformLocation(shader.id, name), x, y);
}

inline void ShaderSetVec3(char name[], void* vec3, const Shader shader)
{
    glUniform3fv(glGetUniformLocation(shader.id, name), 1, vec3);
}

inline void ShaderSetVec3Ex(char name[], float x, float y, float z, const Shader shader)
{
    glUniform3f(glGetUniformLocation(shader.id, name), x, y, z);
}

inline void ShaderSetVec4(char name[], void* vec4, const Shader shader)
{
    glUniform4fv(glGetUniformLocation(shader.id, name), 1, vec4);
}

inline void ShaderSetVec4Ex(char name[], float x, float y, float z, float w, const Shader shader)
{
    glUniform4f(glGetUniformLocation(shader.id, name), x, y, z, w);
}

inline void ShaderSetMat4(char name[], void* mat4, const Shader shader)
{
    glUniformMatrix4fv(glGetUniformLocation(shader.id, name), 1, GL_FALSE, mat4);
}