#include <App.hpp>

void App::Draw()
{
    DrawRectangle(100, 100, 100, 100, RED);
}

void App::Update()
{
    if(IsKeyPressed(KeyboardKey::KEY_F)) {
        ToggleBorderlessWindowed();
    }
}