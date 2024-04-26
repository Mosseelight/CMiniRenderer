#include <stdio.h>
#include "Renderer/Renderer.h"

int main(void)
{
    InitWindow(1280, 720, "Test");
    while (WindowShouldClose())
    {
        UpdateWindow();
    }
    CleanWindow();
    return 0;
}
