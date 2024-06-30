#include "APP.hpp"

const short int WINDOW_WIDTH = 1280;
const short int WINDOW_HEIGHT = 720;
const char* APP_NAME = "Organization App";
const short int APP_FPS = 60;

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, APP_NAME);
    SetTargetFPS(APP_FPS);
    InitAudioDevice();

    APP app;

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        app.Update();

        ClearBackground(LIGHTGRAY);

        app.Draw();
        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}