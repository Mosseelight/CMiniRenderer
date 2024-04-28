#include "Shader.h"

Shader CompileShader(const char* vertexShader, const char* fragmentShader)
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
        printf(infoLog);
    }

    fragShaderU = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShaderU, 1, &fragmentShader, NULL);
    glCompileShader(fragShaderU);
    glGetShaderiv(fragShaderU, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragShaderU, 512, NULL, infoLog);
        printf("Shader type Fragment Failed Compile\n");
        printf(infoLog);
    }

    shader.id = glCreateProgram();

    glAttachShader(shader.id, vertShaderU);
    glAttachShader(shader.id, fragShaderU);
    glLinkProgram(shader.id);
    glGetProgramiv(shader.id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader.id, 512, NULL, infoLog);
        printf("Shader failed linking\n");
        printf(infoLog);
    }

    //maybe will create problem
    glDetachShader(shader.id, vertShaderU);
    glDetachShader(shader.id, fragShaderU);

    glDeleteShader(vertShaderU);
    glDeleteShader(fragShaderU);

    return shader;
}