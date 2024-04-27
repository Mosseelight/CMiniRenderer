#include "Renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Window.h"
#include "Batcher.h"

RendererData _renderData;

void InitMiniRenderer(WindowSettings settings, VertexOffsets* offset)
{
    //  Init our window
    InitWindow(settings);
    InitRenderSet(offset);
}

void UpdateMiniRenderer()
{
    //  Update anything like the renderer
    UpdateWindow();
}

void CleanMiniRenderer()
{
    //  Delete the mesh storage
    free(_renderData._allMeshVertexData);
    free(_renderData._allMeshIndiceData);

    CleanRenderSet();
    CleanWindow();
}

int IsWindowOpen()
{
    //  Return the check if our window should close
    return WindowShouldClose();
}

//  Testing purposes
void AddTriMesh()
{
    float vertexes[] =
    {
        -1.0f, -1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0, 0,

        1.0f, -1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1, 0,

        -1.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0, 1
    };

    uint32_t indices[] =
    {
        0,1,2
    };

    _renderData._allMeshVertexData = malloc(sizeof(vertexes));
    _renderData._allMeshIndiceData = malloc(sizeof(indices));
    memcpy(_renderData._allMeshVertexData, &vertexes, sizeof(vertexes));
    memcpy(_renderData._allMeshIndiceData, &vertexes, sizeof(indices));

    _renderData.meshVertexSize += sizeof(vertexes);
    _renderData.meshIndiceSize += sizeof(indices);

    UpdateRenderSet(_renderData._allMeshVertexData, _renderData._allMeshIndiceData, _renderData.meshVertexSize, _renderData.meshIndiceSize);
}
