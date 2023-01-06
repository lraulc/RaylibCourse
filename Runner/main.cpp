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
    int velocity = 0;
    /******************************************/

    while (!WindowShouldClose())
    {
        // Start Drawing
        BeginDrawing();
        ClearBackground(DARKGRAY);

        // Game Loop

        DrawRectangle(window.width / 2, pos_y, width, height, BLUE);
        if (IsKeyDown(KEY_SPACE))
        {
            velocity -= 10;
        }
        pos_y += velocity;
        // End Drawing
        EndDrawing();
    }
    CloseWindow();
    return 0;
}