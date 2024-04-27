#pragma once

#include <stdint.h>
#include "../Glad/include/glad/glad.h"
#include "Renderer.h"

typedef struct
{
    uint32_t vao;
    uint32_t vbo;
    uint32_t ebo;
} RenderSet;

//  Set up opengl
void InitRenderSet(const VertexOffsets* offsets);
//  Take all mesh data currently in the renderer and send it to the gpu
void UpdateRenderSet(const void* meshVertexData, const void* meshIndiceData, const uint32_t vertexSize, const uint32_t indiceSize);
void CleanRenderSet();