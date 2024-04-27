#include "Renderer.h"
#include "Window.h"
#include "Batcher.h"

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
    CleanWindow();
}

int IsWindowOpen()
{
    //  Return the check if our window should close
    return WindowShouldClose();
}
