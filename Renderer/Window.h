#pragma once
#include <stdint.h>
#include "Renderer.h"

void InitWindow(WindowSettings settings);
void UpdateWindow();
void CleanWindow();
int WindowShouldClose();
void KeyPressed();