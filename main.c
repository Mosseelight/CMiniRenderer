#include <stdio.h>
#include "Renderer/MiniRender.h"

int main(void)
{
    const WindowSettings settings = (WindowSettings){3, 3, 1280, 720, "Window"};
    //  Create a test case of a position, normal and uv for a vertex
    uint8_t offsetCount[] = {3, 3, 2};
    //  All will be 32 bit floats
    uint8_t offsetByte[] = {4,4,4};
    VertexOffsets offset = (VertexOffsets){3, offsetCount, offsetByte, 30, 0};
    InitMiniRenderer(settings, &offset);
    AddTriMesh();
    while (IsWindowOpen())
    {
        UpdateMiniRenderer();
    }

    CleanMiniRenderer();
    return 0;
}
