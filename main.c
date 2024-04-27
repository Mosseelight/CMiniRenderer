#include <stdio.h>
#include "Renderer/MiniRender.h"

int main(void)
{
    const WindowSettings settings = (WindowSettings){3, 3, 1280, 720, "Window"};
    uint8_t offsetCount[] = {3, 3, 2};
    uint8_t offsetByte[] = {4,4,4};
    VertexOffsets offset = (VertexOffsets){3, offsetCount, offsetByte, 30, 0};
    InitMiniRenderer(settings, &offset);
    while (IsWindowOpen())
    {


        UpdateMiniRenderer();
    }
    return 0;
}
