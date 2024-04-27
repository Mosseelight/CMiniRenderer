#pragma once
#include <stdint.h>

void InitWindow(uint16_t sizeX, uint16_t sizeY, char title[]);
void UpdateWindow();
void CleanWindow();
int WindowShouldClose();
void KeyPressed();