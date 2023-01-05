//
// Created by Raul Castillo 01 / 05 / 2023.
//

#include <stdio.h>
#include "raylib.h"

int width = 720;
int height = 512;

bool isRunning = false;

int main()
{
    // Game Loop
    InitWindow(width, height, "First Window");
    isRunning = true;
    while (isRunning)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    return 0;
}