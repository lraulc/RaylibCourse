#include "raylib.h"
#include <stdio.h>

struct window_sizes
{
    int width;
    int height;
};

window_sizes window;
void window_sizes_init()
{
    window.width = 800;
    window.height = 600;
    InitWindow(window.width, window.height, "Runner!");
    SetTargetFPS(60);
}

int main()
{
    // Local Variables
    window_sizes_init();

    // Rectangle dimensions
    const int width = 50;
    const int height = 80;
    // Rectangle Movement
    int pos_y = window.height - height;
    int ground = window.height - height;
    int velocity = 0;
    const int jump_velocity = -25;

    // Acceleration due to gravity (pixels / frame / frame)
    const int gravity = 1;
    /******************************************/

    while (!WindowShouldClose())
    {
        // Start Drawing
        BeginDrawing();
        ClearBackground(DARKGRAY);

        // Ground check
        bool isInAir = false;
        if (pos_y >= ground && !isInAir)
        {
            // Rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // Rectange is in the air
            velocity += gravity;
            isInAir = true;
        }

        // Game Loop

        DrawRectangle(window.width / 2, pos_y, width, height, BLUE);
        // Jump Check
        if (IsKeyDown(KEY_SPACE) && !isInAir)
        {
            velocity += jump_velocity;
        }
        // Update Position
        pos_y += velocity;
        // End Drawing
        EndDrawing();
    }
    CloseWindow();
    return 0;
}