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

void window_sizes_init()
{
    window.x = 720;
    window.y = 512;
}

Color clearColor = {60, 60, 60, 255};
/*************************************************/
bool isRunning = false;

int main()
{
    // Window Struct Init
    window_sizes_init();

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

    // Collision
    bool collision =
        (b_rect_y >= u_circle_y) &&
        (u_rect_y <= b_circle_y) &&
        (r_rect_x >= l_circle_x) &&
        (l_rect_x <= r_circle_x);

    while (isRunning)
    {
        if (!WindowShouldClose())
        {
            // Double buffer creation
            BeginDrawing();
            ClearBackground(clearColor);

            if (collision)
            {
                DrawText("Game Over!", window.x / 2, 200, 20, RED);
            }
            else
            {
                // Draw Start

                /* Update Collision Edges */
                l_circle_x = circle_x - circle_radius;
                r_circle_x = circle_x + circle_radius;
                u_circle_y = circle_y - circle_radius;
                b_circle_y = circle_y + circle_radius;

                l_rect_x = rect_x;
                r_rect_x = rect_x + rect_length;
                u_rect_y = rect_y;
                b_rect_y = rect_y + rect_length;

                /* Update Collision with Rectangle */
                collision = (b_rect_y >= u_circle_y) &&
                            (u_rect_y <= b_circle_y) &&
                            (r_rect_x >= l_circle_x) &&
                            (l_rect_x <= r_circle_x);

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
            }
            // Window Should close

            EndDrawing();
        }
        else
        {
            CloseWindow();
        }
    }
    return 0;
}