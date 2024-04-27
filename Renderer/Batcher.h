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

//  Set up opengl information
void InitRenderSet(const VertexOffsets* offsets);
void UpdateRenderSet();
void CleanRenderSet();