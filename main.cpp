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
        if (!WindowShouldClose())
        {
        // Double buffer creation
        BeginDrawing();

        // Draw Start



        // Window Should close
        // Clear after finished drawing
        ClearBackground(RED);
        EndDrawing();
        }
        else
        {
            CloseWindow();
        }
    }
    return 0;
}