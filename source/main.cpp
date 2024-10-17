#include <App.hpp>

int main()
{
    InitWindow(1280, 720, "App");
    SetTargetFPS(60);

    App app;

    while(!WindowShouldClose())
    {
        BeginDrawing();
            app.Update();
            ClearBackground(LIGHTGRAY);
            app.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}