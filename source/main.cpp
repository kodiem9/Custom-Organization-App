#include <raylib.h>

int main()
{
    InitWindow(1280, 720, "App");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}