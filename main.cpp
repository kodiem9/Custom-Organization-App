#include "include/raylib.h"

int main()
{
    InitWindow(800, 600, "Organization App - v0.1");
    SetTargetFPS(60);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}