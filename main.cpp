#include "APP.hpp"

const short int WINDOW_WIDTH = 1280;
const short int WINDOW_HEIGHT = 720;
const char* APP_NAME = "Organization App";
const short int APP_FPS = 60;

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, APP_NAME);
    SetTargetFPS(APP_FPS);

    APP app;

    while(WindowShouldClose() == false)
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