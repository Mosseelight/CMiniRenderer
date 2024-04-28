#pragma once

#include "../Glad/include/glad/glad.h"
#include <stdint.h>
#include <stdio.h>

typedef struct
{
    uint32_t id;
} Shader;

Shader CompileShader(const char* vertexShader, const char* fragmentShader);

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