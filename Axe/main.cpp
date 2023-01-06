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
    float circle_radius = 25;
    //  Circle Edges
    float l_circle_x = circle_x - circle_radius; // Left distance
    float r_circle_x = circle_x + circle_radius; // Right Distance
    float u_circle_y = circle_y - circle_radius; // Upper Distance
    float b_circle_y = circle_y + circle_radius; // Bottom Distance

    // Rectangle Variables
    float rect_x = 300;
    float rect_y = 0;
    float rect_length = 50;
    int direction = 10; // Will move downwards
    Color rect_color = {172, 200, 123, 255};

    // Rectangle Edges
    float l_rect_x = rect_x;
    float r_rect_x = rect_x + rect_length;
    float u_rect_y = rect_y;
    float b_rect_y = rect_y + rect_length;

    while (isRunning)
    {
        if (!WindowShouldClose())
        {
            // Double buffer creation
            BeginDrawing();

            // Draw Start

            /*********** Draw Cricle Start ****************/
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);

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
            /*********** Draw Cricle END ****************/

            /*********** Draw and Move Square START ****************/
            DrawRectangle(rect_x, rect_y, rect_length, rect_length, rect_color);
            rect_y += direction;

            if ((rect_y >= window.y) || (rect_y <= 0 - 25))
            {
                direction = -direction;
            }

            /*********** Draw Square END ****************/

            /*********** Detect Collision Start ***************/

            /*********** Detect Collision End ***************/

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