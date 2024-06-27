#include "APP.hpp"

APP::APP()
{
    button.Init(Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, 100, 100);
}


// * PUBLIC FUNCTIONS
void APP::Draw()
{
    button.Draw();
}

void APP::Update()
{
    button.Update();
}