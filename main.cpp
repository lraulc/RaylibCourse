//
// Created by Raul Castillo 01 / 05 / 2023.
//

#include <stdio.h>
#include "raylib.h"

/*************************************************/
// Window properties //
struct window_sizes
{
    int x;
    int y;
};
window_sizes window;
Color clearColor = {60, 60, 60, 255};
/*************************************************/
bool isRunning = false;

int main()
{
    window.x = 720;
    window.y = 512;
    // Game Loop
    InitWindow(window.x, window.y, "First Window");
    SetTargetFPS(60);
    isRunning = true;

    // Circle Init Positions
    float circle_x = window.x / 2;
    float circle_y = window.y / 2;

    while (isRunning)
    {
        if (!WindowShouldClose())
        {
            // Double buffer creation
            BeginDrawing();

            // Draw Start
            DrawCircle(circle_x, circle_y, 25, BLUE);

            if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && (circle_x >= 0))
            {
                circle_x -= 10;
            }
            if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && (circle_x < window.x))
            {
                circle_x += 10;
            }
            if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && (circle_y >= 0))
            {
                circle_y -= 10;
            }
            if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && (circle_y < window.y))
            {
                circle_y += 10;
            }

            // Window Should close
            // Clear after finished drawing
            ClearBackground(clearColor);
            EndDrawing();
        }
        else
        {
            CloseWindow();
        }
    }
    return 0;
}